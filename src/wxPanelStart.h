#ifndef WXPANELSTART_H
#define WXPANELSTART_H

#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>

#include "wxPanelBase.h"

class wxPanelStart : public wxPanelBase_
{
public:
    wxPanelStart(wxFrame* parent);
    virtual ~wxPanelStart() = default;

private:
    wxTextCtrl* mEditSource;
    wxTextCtrl* mEditDestination;
    wxButton* mButtonSource;
    wxButton* mButtonDestination;
    wxButton* mButtonLoad;
    wxCheckBox* mSubFolders;
};

#endif // WXPANELSTART_H
