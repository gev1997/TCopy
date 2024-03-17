#include "DirPicker.h"

gui::DirPicker::DirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size)
    : wxDirPickerCtrl{parent, wxID_ANY, wxEmptyString, wxDirSelectorPromptStr, pos, size}
    , mTextCtrl{new DirTextCtrl(this, {0, 3}, {405, 23})}
{
    GetPickerCtrl()->SetLabel(label);

    if (m_text) m_text->Destroy();
    m_text = mTextCtrl;
}

bool gui::DirPicker::IsDirectory() const
{
    return mTextCtrl->IsDirectory();
}
