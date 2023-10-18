#include "wxMainFrame.h"

wxMainFrame::wxMainFrame()
    : wxFrame{nullptr, wxID_ANY, "TCopy"}
    , mFrameStart{new wxPanelStart(this)}
    , mFrameMain{new wxPanelMain(this)}
{
    Display(wxMainFrame::Panel::Start);
}

void wxMainFrame::Display(Panel panel)
{
    mFrameStart->Display(panel == Panel::Start);
    mFrameMain->Display(panel == Panel::Main);
}
