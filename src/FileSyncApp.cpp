#include "FileSyncApp.h"

FileSyncApp::FileSyncApp()
    : mRegistery{}
    , mMainFrame{new GUI::MainFrame()}
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

GUI::MainFrame& FileSyncApp::GetMainFrame()
{
    return *mMainFrame;
}

DB::Manager& FileSyncApp::GetDB()
{
    return mCopyDB;
}

wxIMPLEMENT_APP(FileSyncApp);
