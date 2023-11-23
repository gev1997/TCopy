#ifndef FILESYNCAPP_H
#define FILESYNCAPP_H

#include <memory>

#include <wx/app.h>

#include "wxMainFrame.h"
#include "DB/Manager.h"

class FileSyncApp : public wxApp
{
public:
    FileSyncApp();
    virtual ~FileSyncApp() = default;

    bool OnInit() override;
    wxMainFrame& GetMainFrame();
    DB::Manager& GetDB();

private:
    wxMainFrame* mMainFrame;
    DB::Manager mCopyDB;
};

#endif // FILESYNCAPP_H
