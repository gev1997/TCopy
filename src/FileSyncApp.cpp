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

TCopyDB* TCopyApp::GetDB() const
{
    return mCopyDB.get();
}

wxIMPLEMENT_APP(TCopyApp);
