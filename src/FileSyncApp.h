#ifndef FILESYNCAPP_H
#define FILESYNCAPP_H

#include <memory>

#include <wx/app.h>

#include "wxMainFrame.h"
#include "FileSyncDB.h"

class FileSyncApp : public wxApp
{
public:
    FileSyncApp();
    virtual ~FileSyncApp() = default;

    bool OnInit() override;
    wxMainFrame* GetMainFrame() const;
    FileSyncDB* GetDB() const;

private:
    std::unique_ptr<FileSyncDB> mCopyDB;
    wxMainFrame* mMainFrame;
};

#endif // FILESYNCAPP_H
