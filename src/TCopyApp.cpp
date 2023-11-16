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

wxMainFrame* TCopyApp::GetMainFrame() const
{
    return mMainFrame;
}

wxIMPLEMENT_APP(TCopyApp);
