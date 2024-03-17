#include "DirTextCtrl.h"

GUI::DirTextCtrl::DirTextCtrl(wxWindow* parent, const wxPoint& pos, const wxSize& size)
    : wxTextCtrl{parent, wxID_ANY, wxEmptyString, pos, size}
{
    Bind(wxEVT_TEXT, &DirTextCtrl::OnTextChanged, this);
}

bool GUI::DirTextCtrl::IsDirectory() const
{
    return fs::is_directory(GetValue().ToStdString());
}

void GUI::DirTextCtrl::ValidatePath()
{
    SetForegroundColour(IsDirectory() ? *wxBLACK : *wxRED);
    Refresh();
}

void GUI::DirTextCtrl::ChangeValue(const wxString& value)
{
    SetValue(value);
}

void GUI::DirTextCtrl::OnTextChanged(wxCommandEvent& event)
{
    ValidatePath();
}
