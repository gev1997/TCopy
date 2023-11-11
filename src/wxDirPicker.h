#ifndef WXDIRPICKER
#define WXDIRPICKER

#include <wx/filepicker.h>

class wxDirPicker : public wxDirPickerCtrl
{
public:
    wxDirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size);
};

#endif // WXDIRPICKER
