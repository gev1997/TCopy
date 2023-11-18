#ifndef WXDIRPICKER
#define WXDIRPICKER

#include <wx/filepicker.h>

#include "wxDirTextCtrl.h"

class wxDirPicker : public wxDirPickerCtrl
{
public:
    wxDirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size);
    virtual ~wxDirPicker() = default;

    bool IsDirectory() const;

private:
    void OnDirPickerChanged(wxFileDirPickerEvent& event);

private:
    wxDirTextCtrl* mTextCtrl;
};

#endif // WXDIRPICKER
