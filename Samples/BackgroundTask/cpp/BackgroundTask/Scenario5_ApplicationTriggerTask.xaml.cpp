﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// Scenario4_ApplicationTriggerTask.xaml.cpp
// Implementation of the ApplicationTriggerTask class
//

#include "pch.h"
#include "Scenario5_ApplicationTriggerTask.xaml.h"
#include "SampleConfiguration.h"

using namespace SDKTemplate;
using namespace concurrency;
using namespace Windows::ApplicationModel::Background;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

ApplicationTriggerTask::ApplicationTriggerTask()
{
    InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void ApplicationTriggerTask::OnNavigatedTo(NavigationEventArgs^ e)
{
    // A pointer back to the main page.  This is needed if you want to call methods in MainPage such
    // as NotifyUser()
    rootPage = MainPage::Current;

    //
    // Attach progress and completed handlers to any existing tasks.
    //
    auto iter = BackgroundTaskRegistration::AllTasks->First();
    auto hascur = iter->HasCurrent;
    while (hascur)
    {
        auto cur = iter->Current->Value;

        if (cur->Name == ApplicationTriggerTaskName)
        {
            BackgroundTaskSample::UpdateBackgroundTaskStatus(cur->Name, true);
            AttachProgressAndCompletedHandlers(cur);
            break;
        }

        hascur = iter->MoveNext();
    }

    UpdateUI();
}

/// <summary>
/// Attach progress and completed handers to a background task.
/// </summary>
/// <param name="task">The task to attach progress and completed handlers to.</param>
void ApplicationTriggerTask::AttachProgressAndCompletedHandlers(IBackgroundTaskRegistration^ task)
{
    auto progress = [this](BackgroundTaskRegistration^ task, BackgroundTaskProgressEventArgs^ args)
    {
        auto progress = "Progress: " + args->Progress + "%";
        BackgroundTaskSample::ApplicationTriggerTaskProgress = progress;
        UpdateUI();
    };
    task->Progress += ref new BackgroundTaskProgressEventHandler(progress);

    auto completed = [this](BackgroundTaskRegistration^ task, BackgroundTaskCompletedEventArgs^ args)
    {
        UpdateUI();
    };
    task->Completed += ref new BackgroundTaskCompletedEventHandler(completed);
}

/// <summary>
/// Register a SampleBackgroundTask.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void ApplicationTriggerTask::RegisterBackgroundTask(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    trigger = ref new ApplicationTrigger();

    auto task = BackgroundTaskSample::RegisterBackgroundTask(SampleBackgroundTaskEntryPoint,
                                                             ApplicationTriggerTaskName,
                                                             trigger,
                                                             nullptr);
    AttachProgressAndCompletedHandlers(task);
    UpdateUI();
}

/// <summary>
/// Unregister a SampleBackgroundTask.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void ApplicationTriggerTask::UnregisterBackgroundTask(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    BackgroundTaskSample::UnregisterBackgroundTasks(ApplicationTriggerTaskName);
    BackgroundTaskSample::ApplicationTriggerTaskResult = "";
    UpdateUI();
}

/// <summary>
/// Signal an ApplicationTrigger.
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
void ApplicationTriggerTask::SignalBackgroundTask(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    //
    // Reset the completion status
    //
    auto settings = ApplicationData::Current->LocalSettings->Values;
    settings->Remove(ApplicationTriggerTaskName);

    //
    // Signal the ApplicationTrigger
    //
    auto request = create_task(trigger->RequestAsync());
    request.then([this](ApplicationTriggerResult result) {
        BackgroundTaskSample::ApplicationTriggerTaskResult = "Signal Result: " + result.ToString();
    });
    UpdateUI();
}

/// <summary>
/// Update the scenario UI.
/// </summary>
void ApplicationTriggerTask::UpdateUI()
{
    auto uiDelegate = [this]()
    {
        RegisterButton->IsEnabled = !BackgroundTaskSample::ApplicationTriggerTaskRegistered;
        UnregisterButton->IsEnabled = BackgroundTaskSample::ApplicationTriggerTaskRegistered;
        SignalButton->IsEnabled = BackgroundTaskSample::ApplicationTriggerTaskRegistered & (trigger != nullptr);
        Progress->Text = BackgroundTaskSample::ApplicationTriggerTaskProgress;
        Result->Text = BackgroundTaskSample::ApplicationTriggerTaskResult;
        Status->Text = BackgroundTaskSample::GetBackgroundTaskStatus(ApplicationTriggerTaskName);
    };
    auto handler = ref new Windows::UI::Core::DispatchedHandler(uiDelegate, Platform::CallbackContext::Any);

    Dispatcher->RunAsync(CoreDispatcherPriority::Normal, handler);
}
