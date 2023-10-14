#include "wxMainFrame.h"

wxMainFrame::wxMainFrame()
    : wxFrame{nullptr, wxID_ANY, "TCopy"}
    , mFrameStart{new wxPanelStart(this)}
    , mFrameMain{new wxPanelMain(this)}
{
    Display(wxMainFrame::Panel::Start, true);
    Display(wxMainFrame::Panel::Main, false);
}

void wxMainFrame::Display(Panel panel, bool show)
{
    switch (panel)
    {
        case Panel::Start:
            mFrameStart->Display(show);
            break;
        case Panel::Main:
            mFrameMain->Display(show);
            break;
    }
}
