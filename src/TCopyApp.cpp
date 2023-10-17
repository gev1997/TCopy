#include <iostream>

#include "TCopyApp.h"

TCopyApp::TCopyApp()
    : mMainFrame{new wxMainFrame()}
{}

bool TCopyApp::OnInit()
{
    assert(mMainFrame);
    mMainFrame->Show();
    mMainFrame->Centre();

    return true;
}

wxIMPLEMENT_APP(TCopyApp);
