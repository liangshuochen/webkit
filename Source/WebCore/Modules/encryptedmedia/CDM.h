/*
 * Copyright (C) 2016 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if ENABLE(ENCRYPTED_MEDIA)

#include "ContextDestructionObserver.h"
#include "MediaKeySystemConfiguration.h"
#include "SharedBuffer.h"
#include <functional>
#include <wtf/HashSet.h>
#include <wtf/Ref.h>
#include <wtf/RefCounted.h>
#include <wtf/WeakPtr.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class CDM;
class CDMInstance;
class CDMPrivate;
class Document;
class ScriptExecutionContext;
class SharedBuffer;

struct MediaKeysRestrictions;

class CDMFactory {
public:
    virtual ~CDMFactory() { };
    virtual std::unique_ptr<CDMPrivate> createCDM(CDM&) = 0;
    virtual bool supportsKeySystem(const String&) = 0;
};

class CDM : public RefCounted<CDM>, private ContextDestructionObserver {
public:
    WEBCORE_EXPORT static void registerCDMFactory(CDMFactory&);
    WEBCORE_EXPORT static void unregisterCDMFactory(CDMFactory&);

    static bool supportsKeySystem(const String&);
    static bool isPersistentType(MediaKeySessionType);

    static Ref<CDM> create(Document&, const String& keySystem);
    ~CDM();

    using SupportedConfigurationCallback = std::function<void(std::optional<MediaKeySystemConfiguration>)>;
    void getSupportedConfiguration(MediaKeySystemConfiguration&& candidateConfiguration, SupportedConfigurationCallback&&);

    const String& keySystem() const { return m_keySystem; }

    void loadAndInitialize();
    RefPtr<CDMInstance> createInstance();
    bool supportsServerCertificates() const;
    bool supportsSessions() const;
    bool supportsInitDataType(const AtomicString&) const;

    RefPtr<SharedBuffer> sanitizeInitData(const AtomicString& initDataType, const SharedBuffer&);
    bool supportsInitData(const AtomicString& initDataType, const SharedBuffer&);

private:
    CDM(Document&, const String& keySystem);

    enum class ConfigurationStatus {
        Supported,
        NotSupported,
        ConsentDenied,
    };

    enum class ConsentStatus {
        ConsentDenied,
        InformUser,
        Allowed,
    };

    enum class AudioVideoType {
        Audio,
        Video,
    };

    void doSupportedConfigurationStep(MediaKeySystemConfiguration&& candidateConfiguration, MediaKeysRestrictions&&, SupportedConfigurationCallback&&);
    std::optional<MediaKeySystemConfiguration>  getSupportedConfiguration(const MediaKeySystemConfiguration& candidateConfiguration, MediaKeysRestrictions&);
    std::optional<Vector<MediaKeySystemMediaCapability>> getSupportedCapabilitiesForAudioVideoType(AudioVideoType, const Vector<MediaKeySystemMediaCapability>& requestedCapabilities, const MediaKeySystemConfiguration& partialConfiguration, MediaKeysRestrictions&);

    WeakPtr<CDM> createWeakPtr() { return m_weakPtrFactory.createWeakPtr(); }

    using ConsentStatusCallback = std::function<void(ConsentStatus, MediaKeySystemConfiguration&&, MediaKeysRestrictions&&)>;
    void getConsentStatus(MediaKeySystemConfiguration&& accumulatedConfiguration, MediaKeysRestrictions&&, ConsentStatusCallback&&);
    String m_keySystem;
    std::unique_ptr<CDMPrivate> m_private;
    WeakPtrFactory<CDM> m_weakPtrFactory;
};

}

#endif
