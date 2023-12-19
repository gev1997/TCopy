#include "wxPanelBase.h"
#include "FileSyncApp.h"

wxPanelBase_::wxPanelBase_(wxFrame* parent, const wxSize& size)
    : wxPanel{parent, wxID_ANY, wxDefaultPosition, size}
    , mApp{dynamic_cast<FileSyncApp&>(*wxApp::GetInstance())}
{}

void wxPanelBase_::Display(bool show)
{
    if (show)
    {
        wxWindow* parent = GetParent();
        assert(parent);
        parent->SetSize(GetSize());
    }

    Show(show);
}
