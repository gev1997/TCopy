#include "wxDirPicker.h"

wxDirPicker::wxDirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size)
    : wxDirPickerCtrl{parent, wxID_ANY, wxEmptyString, wxDirSelectorPromptStr, pos, size}
{
    GetPickerCtrl()->SetLabel(label);
}
