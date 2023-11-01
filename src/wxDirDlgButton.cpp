#include <wx/dirdlg.h>

#include "wxDirDlgButton.h"

wxDirDlgButton::wxDirDlgButton(wxWindow* parent, wxTextCtrl* targetEdit,
                               const wxString& label, const wxPoint& pos, const wxSize& size)
    : wxButton{parent, wxID_ANY, label, pos, size}
    , mTargetEdit{targetEdit}
{
    assert(mTargetEdit);
    Bind(wxEVT_BUTTON, &wxDirDlgButton::OnClick, this);
}

void wxDirDlgButton::OnClick(wxCommandEvent&)
{
    const wxString dirDlgTitle{"Choose " + GetLabel() + "directory"};
    wxDirDialog dirDlg(this, dirDlgTitle, mTargetEdit->GetValue(), wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    if (dirDlg.ShowModal() == wxID_OK)
        mTargetEdit->SetLabelText(dirDlg.GetPath());
}
