#include "wxDirTextCtrl.h"

gui::DirTextCtrl::DirTextCtrl(wxWindow* parent, const wxPoint& pos, const wxSize& size)
    : wxTextCtrl{parent, wxID_ANY, wxEmptyString, pos, size}
{
    Bind(wxEVT_TEXT, &DirTextCtrl::OnTextChanged, this);
}

bool gui::DirTextCtrl::IsDirectory() const
{
    return fs::is_directory(GetValue().ToStdString());
}

void gui::DirTextCtrl::ValidatePath()
{
    SetForegroundColour(IsDirectory() ? *wxBLACK : *wxRED);
    Refresh();
}

void gui::DirTextCtrl::ChangeValue(const wxString& value)
{
    SetValue(value);
}

void gui::DirTextCtrl::OnTextChanged(wxCommandEvent& event)
{
    ValidatePath();
}
