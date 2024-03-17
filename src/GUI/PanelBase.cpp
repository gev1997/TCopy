#include "PanelBase.h"
#include "../FileSyncApp.h"

GUI::PanelBase::PanelBase(wxFrame* parent, const wxSize& size)
    : wxPanel{parent, wxID_ANY, wxDefaultPosition, size}
    , mApp{dynamic_cast<FileSyncApp&>(*wxApp::GetInstance())}
{}

void GUI::PanelBase::Display(bool show)
{
    if (show)
    {
        wxWindow* parent = GetParent();
        assert(parent);
        parent->SetSize(GetSize());
    }

    Show(show);
}
