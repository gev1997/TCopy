#ifndef TCOPYAPP_H
#define TCOPYAPP_H

#include <memory>

#include <wx/app.h>

#include "wxMainFrame.h"
#include "TCopyDB.h"

class TCopyApp : public wxApp
{
public:
    TCopyApp();
    virtual ~TCopyApp() = default;

    bool OnInit() override;
    wxMainFrame* GetMainFrame() const;

private:
    std::unique_ptr<TCopyDB> mCopyDB;
    wxMainFrame* mMainFrame;
};

#endif // TCOPYAPP_H
