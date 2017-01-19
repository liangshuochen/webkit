# webkit
JSC bindingTest (forked Unofficial mirror of the WebKit SVN repository)


> 测试用例的js代码 
> 参考https://github.com/domchen/V8Performace

|      -        |    JIT    |   NO JIT   |
| :-----------  | :--------: | :--------:  |
| JSC API binding |    ![Alt text](./-public-jit.png)  |  ![Alt text](./-public-nojit.png)  |
| JSC private binding | ![Alt text](./-private-jit.png)| ![Alt text](./-private-nojit.png)    |

表格里的图为在测试用例js代码片段在jsc里运行的时间日志。其中，
- JS--Time: 纯JS测试耗时，Rectangle.setTo, Matrix.transformBounds类在js里实现。
- JS--NoField--Time: 不含属性读写的纯JS。
- JSBinding--Time: 绑定方式测试耗时。将c++的Matrix类绑定为JS对象执行Matrix.transformBounds方法；将c++的Rectangle类绑定为JS对象执行Rectangle.setTo; 其中函数setTo传参为4个float, transformBounds传参为js对象。
- JSBinding2--Time: 同上，但是将setTo绑定函数传参为一个TypedArray.

而 JSC API binding是使用JSC对外API绑定机制。而private binding则是直接操作JS virtual machine的绑定机制，即safari的dom节点，webGL采用的绑定机制。

**结论**
1. 使用JIT的情况下，safari使用的JSC内部绑定机制比JSC对外API的绑定机制，在传参为number时效率高为8~9倍，传参为typedArray时效率高7~8倍。
2. 如果不使用JIT，效率高5倍左右，说明c++绑定为js对象的传数据阶段的效率，与是否开启JIT没有太大影响。
3. 如果Rectangle，Matrix为纯JS实现，则是否开启JIT相差35倍左右。
