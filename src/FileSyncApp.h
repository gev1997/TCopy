#pragma once

#include <wx/app.h>

#include "GUI/MainFrame.h"
#include "DB/Manager.h"
#include "FileSyncRegistery.h"

class FileSyncApp : public wxApp
{
public:
    FileSyncApp();
    virtual ~FileSyncApp() = default;

    bool OnInit() override;
    FileSyncRegistery& GetRegistery();
    GUI::MainFrame& GetMainFrame();
    DB::Manager& GetDB();

private:
    FileSyncRegistery mRegistery;
    GUI::MainFrame* mMainFrame;
    DB::Manager mCopyDB;
};
