#ifndef TCOPYAPP_H
#define TCOPYAPP_H

#include <wx/app.h>

#include "wxMainFrame.h"

class TCopyApp : public wxApp
{
public:
    TCopyApp();
    virtual ~TCopyApp() = default;
    bool OnInit() override;

private:
//     TCopyDB*;
    wxMainFrame* mFrameContainer;
};

#endif // TCOPYAPP_H
