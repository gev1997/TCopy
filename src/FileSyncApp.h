#pragma once

#include <wx/app.h>

#include "gui/MainFrame.h"
#include "DB/Manager.h"
#include "FileSyncRegistery.h"

class FileSyncApp : public wxApp
{
public:
    FileSyncApp();
    virtual ~FileSyncApp() = default;

    bool OnInit() override;
    FileSyncRegistery& GetRegistery();
    gui::MainFrame& GetMainFrame();
    DB::Manager& GetDB();

private:
    FileSyncRegistery mRegistery;
    gui::MainFrame* mMainFrame;
    DB::Manager mCopyDB;
};
