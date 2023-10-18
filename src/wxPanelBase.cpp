#include "wxPanelBase.h"

wxPanelBase_::wxPanelBase_(wxFrame* parent)
    : wxPanel{parent, wxID_ANY}
{}

void wxPanelBase_::Display(bool show)
{
    if (show)
    {
        wxWindow* parent = GetParent();
        assert(parent);
        SetSize(mSize);
        parent->SetSizeHints(mSize, mSize);
    }

    Show(show);
}
