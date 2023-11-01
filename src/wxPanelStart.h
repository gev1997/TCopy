#ifndef WXPANELSTART_H
#define WXPANELSTART_H

#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>

#include "wxPanelBase.h"
#include "wxDirDlgButton.h"

class wxPanelStart : public wxPanelBase_
{
public:
    wxPanelStart(wxFrame* parent);
    virtual ~wxPanelStart() = default;

private:
    void ButtonLoadClicked(wxCommandEvent& event);

private:
    wxTextCtrl* mEditSource;
    wxTextCtrl* mEditDestination;
    wxDirDlgButton* mButtonSource;
    wxDirDlgButton* mButtonDestination;
    wxButton* mButtonLoad;
    wxCheckBox* mSubFolders;
};

#endif // WXPANELSTART_H
