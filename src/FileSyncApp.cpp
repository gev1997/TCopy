#include "FileSyncApp.h"

FileSyncApp::FileSyncApp()
    : mRegistery{}
    , mMainFrame{new wxMainFrame()}
    , mCopyDB{}
{}

bool FileSyncApp::OnInit()
{
    assert(mMainFrame);
    mMainFrame->Show();
    mMainFrame->Centre();

    return true;
}

FileSyncRegistery& FileSyncApp::GetRegistery()
{
    return mRegistery;
}

wxMainFrame& FileSyncApp::GetMainFrame()
{
    return *mMainFrame;
}

DB::Manager& FileSyncApp::GetDB()
{
    return mCopyDB;
}

wxIMPLEMENT_APP(FileSyncApp);
