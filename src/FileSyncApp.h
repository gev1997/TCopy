#pragma once

#include <wx/app.h>

#include "gui/wxMainFrame.h"
#include "DB/Manager.h"
#include "FileSyncRegistery.h"

class FileSyncApp : public wxApp
{
public:
    FileSyncApp();
    virtual ~FileSyncApp() = default;

    bool OnInit() override;
    FileSyncRegistery& GetRegistery();
    wxMainFrame& GetMainFrame();
    DB::Manager& GetDB();

private:
    FileSyncRegistery mRegistery;
    wxMainFrame* mMainFrame;
    DB::Manager mCopyDB;
};
