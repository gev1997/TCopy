#include "wxPanelMain.h"

wxPanelMain::wxPanelMain(wxFrame* parent)
    : wxPanelBase_{parent, {600, 500}}
{
    SetBackgroundColour(*wxBLUE);
}
