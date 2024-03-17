#pragma once

#include <wx/filepicker.h>

#include "DirTextCtrl.h"

namespace GUI { class DirPicker; };

class GUI::DirPicker : public wxDirPickerCtrl
{
public:
    DirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size);
    virtual ~DirPicker() = default;

    bool IsDirectory() const;

private:
    DirTextCtrl* mTextCtrl;
};
