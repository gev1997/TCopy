#ifndef WXDIRTEXTCTRL
#define WXDIRTEXTCTRL

#include <filesystem>

#include <wx/textctrl.h>

namespace fs = std::filesystem;

class wxDirTextCtrl : public wxTextCtrl
{
public:
    wxDirTextCtrl(wxWindow* parent, const wxPoint& pos, const wxSize& size);
    virtual ~wxDirTextCtrl() = default;

    bool IsDirectory() const;
    void ValidatePath();

private:
    void OnTextChanged(wxCommandEvent& event);
};

#endif // WXDIRTEXTCTRL
