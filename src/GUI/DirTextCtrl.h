#pragma once

#include <wx/textctrl.h>

namespace GUI { class DirTextCtrl; };

class GUI::DirTextCtrl : public wxTextCtrl
{
public:
    DirTextCtrl(wxWindow* parent, const wxPoint& pos, const wxSize& size);
    virtual ~DirTextCtrl() = default;

    bool IsDirectory() const;

private:
    void ValidatePath();
    void ChangeValue(const wxString& value) override;
    void OnTextChanged(wxCommandEvent& event);
};
