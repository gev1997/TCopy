#include "wxPanelStart.h"

wxPanelStart::wxPanelStart(wxFrame* parent)
    : wxPanelBase_{parent}
{
    mSize.Set(500, 250);
    SetBackgroundColour(*wxRED);
}
