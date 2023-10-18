#include "wxPanelMain.h"

wxPanelMain::wxPanelMain(wxFrame* parent)
    : wxPanelBase_{parent}
{
    mSize.Set(600, 500);
    SetBackgroundColour(*wxBLUE);
}
