#include "wxMainFrame.h"

wxMainFrame::wxMainFrame()
    : wxFrame{nullptr, wxID_ANY, "File Sync"}
    , mPanelStart{new wxPanelStart(this)}
    , mPanelMain{new wxPanelMain(this)}
{
    Display(wxMainFrame::Panel::Start);
}

void wxMainFrame::Display(Panel panel)
{
    mPanelStart->Display(panel == Panel::Start);
    mPanelMain->Display(panel == Panel::Main);
}
