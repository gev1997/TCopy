#include "wxDirTextCtrl.h"

wxDirTextCtrl::wxDirTextCtrl(wxWindow* parent, const wxPoint& pos, const wxSize& size)
    : wxTextCtrl{parent, wxID_ANY, wxEmptyString, pos, size}
{
    Bind(wxEVT_TEXT, &wxDirTextCtrl::OnTextChanged, this);
}

bool wxDirTextCtrl::IsDirectory() const
{
    return fs::is_directory(GetValue().ToStdString());
}

void wxDirTextCtrl::ValidatePath()
{
    SetForegroundColour(IsDirectory() ? *wxBLACK : *wxRED);
    Refresh();
}

void wxDirTextCtrl::ChangeValue(const wxString& value)
{
    SetValue(value);
}

void wxDirTextCtrl::OnTextChanged(wxCommandEvent& event)
{
    ValidatePath();
}
