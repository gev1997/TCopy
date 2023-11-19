#include "wxPanelBase.h"
#include "FileSyncApp.h"

wxPanelBase_::wxPanelBase_(wxFrame* parent, const wxSize& size)
    : wxPanel{parent}
    , mApp{dynamic_cast<FileSyncApp&>(*wxApp::GetInstance())}
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
