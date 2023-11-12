#include "wxDirPicker.h"

wxDirPicker::wxDirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size)
    : wxDirPickerCtrl{parent, wxID_ANY, wxEmptyString, wxDirSelectorPromptStr, pos, size}
    , mTextCtrl{new wxDirTextCtrl(this, {0, 3}, {405, 23})}
{
    GetPickerCtrl()->SetLabel(label);
    delete GetTextCtrl();
    SetTextCtrl(mTextCtrl);

    Bind(wxEVT_DIRPICKER_CHANGED, &wxDirPicker::OnDirPickerChanged, this);
}

void wxDirPicker::OnDirPickerChanged(wxFileDirPickerEvent& event)
{
    mTextCtrl->ValidatePath();
}
