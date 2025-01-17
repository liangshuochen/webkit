
class ComponentBase {
    constructor(name)
    {
        this._componentName = name || ComponentBase._componentByClass.get(new.target);

        const currentlyConstructed = ComponentBase._currentlyConstructedByInterface;
        let element = currentlyConstructed.get(new.target);
        if (!element) {
            currentlyConstructed.set(new.target, this);
            element = document.createElement(this._componentName);
            currentlyConstructed.delete(new.target);
        }
        element.component = () => { return this };

        this._element = element;
        this._shadow = null;
    }

    element() { return this._element; }
    content()
    {
        this._ensureShadowTree();
        return this._shadow;
    }

    render() { this._ensureShadowTree(); }

    updateRendering()
    {
        Instrumentation.startMeasuringTime('ComponentBase', 'updateRendering');
        this.render();
        Instrumentation.endMeasuringTime('ComponentBase', 'updateRendering');
    }

    renderReplace(element, content) { ComponentBase.renderReplace(element, content); }

    static renderReplace(element, content)
    {
        element.innerHTML = '';
        if (content)
            ComponentBase._addContentToElement(element, content);
    }

    _ensureShadowTree()
    {
        if (this._shadow)
            return;

        const newTarget = this.__proto__.constructor;
        const htmlTemplate = newTarget['htmlTemplate'];
        const cssTemplate = newTarget['cssTemplate'];

        if (!htmlTemplate && !cssTemplate)
            return;

        const shadow = this._element.attachShadow({mode: 'closed'});

        if (htmlTemplate) {
            const template = document.createElement('template');
            template.innerHTML = newTarget.htmlTemplate();
            shadow.appendChild(document.importNode(template.content, true));
            this._recursivelyReplaceUnknownElementsByComponents(shadow);
        }

        if (cssTemplate) {
            const style = document.createElement('style');
            style.textContent = newTarget.cssTemplate();
            shadow.appendChild(style);
        }

        this._shadow = shadow;
    }

    _recursivelyReplaceUnknownElementsByComponents(parent)
    {
        let nextSibling;
        for (let child = parent.firstChild; child; child = child.nextSibling) {
            if (child instanceof HTMLElement && !child.component) {
                const elementInterface = ComponentBase._componentByName.get(child.localName);
                if (elementInterface) {
                    const component = new elementInterface();
                    const newChild = component.element();
                    parent.replaceChild(newChild, child);
                    child = newChild;
                }
            }
            this._recursivelyReplaceUnknownElementsByComponents(child);
        }
    }

    static defineElement(name, elementInterface)
    {
        ComponentBase._componentByName.set(name, elementInterface);
        ComponentBase._componentByClass.set(elementInterface, name);

        if (!window.customElements)
            return;

        class elementClass extends HTMLElement {
            constructor()
            {
                super();

                const currentlyConstructed = ComponentBase._currentlyConstructedByInterface;
                const component = currentlyConstructed.get(elementInterface);
                if (component)
                    return; // ComponentBase's constructor will take care of the rest.

                currentlyConstructed.set(elementInterface, this);
                new elementInterface();
                currentlyConstructed.delete(elementInterface);
            }
        }

        const nameDescriptor = Object.getOwnPropertyDescriptor(elementClass, 'name');
        nameDescriptor.value = `${elementInterface.name}Element`;
        Object.defineProperty(elementClass, 'name', nameDescriptor);

        customElements.define(name, elementClass);
    }

    static createElement(name, attributes, content)
    {
        var element = document.createElement(name);
        if (!content && (attributes instanceof Array || attributes instanceof Node
            || attributes instanceof ComponentBase || typeof(attributes) != 'object')) {
            content = attributes;
            attributes = {};
        }

        if (attributes) {
            for (var name in attributes) {
                if (name.startsWith('on'))
                    element.addEventListener(name.substring(2), attributes[name]);
                else
                    element.setAttribute(name, attributes[name]);
            }
        }

        if (content)
            ComponentBase._addContentToElement(element, content);

        return element;
    }

    static _addContentToElement(element, content)
    {
        if (content instanceof Array) {
            for (var nestedChild of content)
                this._addContentToElement(element, nestedChild);
        } else if (content instanceof Node)
            element.appendChild(content);
         else if (content instanceof ComponentBase)
            element.appendChild(content.element());
        else
            element.appendChild(document.createTextNode(content));
    }

    static createLink(content, titleOrCallback, callback, isExternal)
    {
        var title = titleOrCallback;
        if (callback === undefined) {
            title = content;
            callback = titleOrCallback;
        }

        var attributes = {
            href: '#',
            title: title,
        };

        if (typeof(callback) === 'string')
            attributes['href'] = callback;
        else
            attributes['onclick'] = ComponentBase.createActionHandler(callback);

        if (isExternal)
            attributes['target'] = '_blank';
        return ComponentBase.createElement('a', attributes, content);
    }

    static createActionHandler(callback)
    {
        return function (event) {
            event.preventDefault();
            event.stopPropagation();
            callback.call(this, event);
        };
    }
}

ComponentBase._componentByName = new Map;
ComponentBase._componentByClass = new Map;
ComponentBase._currentlyConstructedByInterface = new Map;

ComponentBase.css = Symbol();
ComponentBase.html = Symbol();
ComponentBase.map = {};
