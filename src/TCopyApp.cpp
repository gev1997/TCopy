#include <iostream>

#include "TCopyApp.h"

TCopyApp::TCopyApp()
    : mMainFrame{new wxMainFrame()}
    , mCopyDB{new TCopyDB()}
{}

bool TCopyApp::OnInit()
{
    assert(mMainFrame);
    assert(mCopyDB);
    mMainFrame->Show();
    mMainFrame->Centre();

    return true;
}

wxIMPLEMENT_APP(TCopyApp);
