#include "wxPanelMain.h"

wxPanelMain::wxPanelMain(wxFrame* parent)
    : wxPanel{parent, wxID_ANY}
    , mSize{300, 300}
{
    SetBackgroundColour(*wxBLUE);
}

void wxPanelMain::Display(bool show)
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
