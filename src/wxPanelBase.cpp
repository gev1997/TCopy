#include "wxPanelBase.h"

wxPanelBase_::wxPanelBase_(wxFrame* parent, const wxSize& size)
    : wxPanel{parent, wxID_ANY}
    , mSize{size}
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
