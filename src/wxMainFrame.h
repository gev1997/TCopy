#pragma once

#include <wx/frame.h>

#include "wxPanelStart.h"
#include "wxPanelMain.h"

class FileSyncApp;

class wxMainFrame : public wxFrame
{
public:
    enum class Panel { Start, Main };

    wxMainFrame();
    virtual ~wxMainFrame() = default;

    void Load();
    void Back();

private:
    void Display(Panel panel);

private:
    FileSyncApp& mApp;
    wxPanelStart* mPanelStart;
    wxPanelMain* mPanelMain;
};
