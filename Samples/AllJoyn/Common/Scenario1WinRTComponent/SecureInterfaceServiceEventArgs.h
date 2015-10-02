//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace com { namespace microsoft { namespace Samples { namespace SecureInterface {

// Methods
public ref class SecureInterfaceConcatenateCalledEventArgs sealed
{
public:
    SecureInterfaceConcatenateCalledEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberInStr1, _In_ Platform::String^ interfaceMemberInStr2);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property SecureInterfaceConcatenateResult^ Result
    {
        SecureInterfaceConcatenateResult^ get() { return m_result; }
        void set(_In_ SecureInterfaceConcatenateResult^ value) { m_result = value; }
    }

    property Platform::String^ InStr1
    {
        Platform::String^ get() { return m_interfaceMemberInStr1; }
    }

    property Platform::String^ InStr2
    {
        Platform::String^ get() { return m_interfaceMemberInStr2; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<SecureInterfaceConcatenateResult^>^ GetResultAsync(SecureInterfaceConcatenateCalledEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<SecureInterfaceConcatenateResult^>
        {
            return t;
        });
    }
    
private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<SecureInterfaceConcatenateResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    SecureInterfaceConcatenateResult^ m_result;
    Platform::String^ m_interfaceMemberInStr1;
    Platform::String^ m_interfaceMemberInStr2;
};

// Readable Properties
public ref class SecureInterfaceGetIsUpperCaseEnabledRequestedEventArgs sealed
{
public:
    SecureInterfaceGetIsUpperCaseEnabledRequestedEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property SecureInterfaceGetIsUpperCaseEnabledResult^ Result
    {
        SecureInterfaceGetIsUpperCaseEnabledResult^ get() { return m_result; }
        void set(_In_ SecureInterfaceGetIsUpperCaseEnabledResult^ value) { m_result = value; }
    }

    Windows::Foundation::Deferral^ GetDeferral();

    static Windows::Foundation::IAsyncOperation<SecureInterfaceGetIsUpperCaseEnabledResult^>^ GetResultAsync(SecureInterfaceGetIsUpperCaseEnabledRequestedEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<SecureInterfaceGetIsUpperCaseEnabledResult^>
        {
            return t;
        });
    }

private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<SecureInterfaceGetIsUpperCaseEnabledResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    SecureInterfaceGetIsUpperCaseEnabledResult^ m_result;
};

// Writable Properties
public ref class SecureInterfaceSetIsUpperCaseEnabledRequestedEventArgs sealed
{
public:
    SecureInterfaceSetIsUpperCaseEnabledRequestedEventArgs(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ bool value);

    property Windows::Devices::AllJoyn::AllJoynMessageInfo^ MessageInfo
    {
        Windows::Devices::AllJoyn::AllJoynMessageInfo^ get() { return m_messageInfo; }
    }

    property bool Value
    {
        bool get() { return m_value; }
    }

    property SecureInterfaceSetIsUpperCaseEnabledResult^ Result
    {
        SecureInterfaceSetIsUpperCaseEnabledResult^ get() { return m_result; }
        void set(_In_ SecureInterfaceSetIsUpperCaseEnabledResult^ value) { m_result = value; }
    }

    static Windows::Foundation::IAsyncOperation<SecureInterfaceSetIsUpperCaseEnabledResult^>^ GetResultAsync(SecureInterfaceSetIsUpperCaseEnabledRequestedEventArgs^ args)
    {
        args->InvokeAllFinished();
        auto t = concurrency::create_task(args->m_tce);
        return concurrency::create_async([t]() -> concurrency::task<SecureInterfaceSetIsUpperCaseEnabledResult^>
        {
            return t;
        });
    }

    Windows::Foundation::Deferral^ GetDeferral();

private:
    void Complete();
    void InvokeAllFinished();
    void InvokeCompleteHandler();

    bool m_raised;
    int m_completionsRequired;
    concurrency::task_completion_event<SecureInterfaceSetIsUpperCaseEnabledResult^> m_tce;
    std::mutex m_lock;
    Windows::Devices::AllJoyn::AllJoynMessageInfo^ m_messageInfo;
    bool m_value;
    SecureInterfaceSetIsUpperCaseEnabledResult^ m_result;
};

} } } } 
