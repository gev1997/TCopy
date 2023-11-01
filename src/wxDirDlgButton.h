#ifndef WXDIRDLGBUTTON
#define WXDIRDLGBUTTON

#include <wx/button.h>
#include <wx/textctrl.h>

class wxDirDlgButton : public wxButton
{
public:
    wxDirDlgButton(wxWindow* parent, wxTextCtrl* targetEdit,
                   const wxString& label, const wxPoint& pos, const wxSize& size);

private:
    void OnClick(wxCommandEvent&);

    wxTextCtrl* mTargetEdit;
};

#endif // WXDIRDLGBUTTON
