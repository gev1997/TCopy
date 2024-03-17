#pragma once

#include <wx/filepicker.h>

#include "wxDirTextCtrl.h"

namespace gui { class DirPicker; };

class gui::DirPicker : public wxDirPickerCtrl
{
public:
    DirPicker(wxWindow* parent, const wxString& label, const wxPoint& pos, const wxSize& size);
    virtual ~DirPicker() = default;

    bool IsDirectory() const;

private:
    DirTextCtrl* mTextCtrl;
};
