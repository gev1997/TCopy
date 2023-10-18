#ifndef WXMAINFRAME_H
#define WXMAINFRAME_H

#include <iostream>

#include <wx/frame.h>

#include "wxPanelStart.h"
#include "wxPanelMain.h"

class wxMainFrame : public wxFrame
{
public:
    enum class Panel { Start, Main };

    wxMainFrame();
    virtual ~wxMainFrame() = default;

    void Display(Panel panel);

private:
    wxPanelStart* mFrameStart;
    wxPanelMain* mFrameMain;
};

#endif // WXMAINFRAME_H
