﻿

//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"
#include "MainPage.xaml.h"




void ::GameEngine::MainPage::InitializeComponent()
{
    if (_contentLoaded)
        return;

    _contentLoaded = true;

    // Call LoadComponent on ms-appx:///MainPage.xaml
    ::Windows::UI::Xaml::Application::LoadComponent(this, ref new ::Windows::Foundation::Uri(L"ms-appx:///MainPage.xaml"), ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);

    // Get the Image named 'imageRendering'
    imageRendering = safe_cast<::Windows::UI::Xaml::Controls::Image^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"imageRendering"));
}

void ::GameEngine::MainPage::Connect(int connectionId, Platform::Object^ target)
{
    switch (connectionId)
    {
    case 1:
        (safe_cast<::Windows::UI::Xaml::UIElement^>(target))->PointerPressed +=
            ref new ::Windows::UI::Xaml::Input::PointerEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::Input::PointerRoutedEventArgs^))&MainPage::Border_PointerPressed);
        (safe_cast<::Windows::UI::Xaml::UIElement^>(target))->PointerReleased +=
            ref new ::Windows::UI::Xaml::Input::PointerEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::Input::PointerRoutedEventArgs^))&MainPage::Border_PointerReleased);
        break;
    case 2:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Button_Click);
        break;
    case 3:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Button_Click_1);
        break;
    case 4:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Button_Click_3);
        break;
    case 5:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Button_Click_2);
        break;
    case 6:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::GameEngine::MainPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Button_Click_4);
        break;
    }
    (void)connectionId; // Unused parameter
    (void)target; // Unused parameter
    _contentLoaded = true;
}
