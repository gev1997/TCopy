#include "wxPanelStart.h"

wxPanelStart::wxPanelStart(wxFrame* parent)
    : wxPanel{parent, wxID_ANY}
    , mSize{200, 200}
{
    SetBackgroundColour(*wxRED);
}

void wxPanelStart::Display(bool show)
{
    if (show)
    {
        wxWindow* parent = GetParent();
        assert(parent);
        SetSize(mSize);
        parent->SetSize(mSize);
    }

    Show(show);
}
