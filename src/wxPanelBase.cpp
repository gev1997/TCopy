#include "wxPanelBase.h"
#include "TCopyApp.h"

wxPanelBase_::wxPanelBase_(wxFrame* parent, const wxSize& size)
    : wxPanel{parent}
    , mApp{dynamic_cast<TCopyApp&>(*wxApp::GetInstance())}
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
