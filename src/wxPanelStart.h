#ifndef WXPANELSTART_H
#define WXPANELSTART_H

#include <wx/button.h>
#include <wx/checkbox.h>

#include "wxPanelBase.h"
#include "wxDirPicker.h"

class wxPanelStart : public wxPanelBase_
{
public:
    wxPanelStart(wxFrame* parent);
    virtual ~wxPanelStart() = default;

private:
    void OnLoadClicked(wxCommandEvent& event);

private:
    wxDirPicker* mSourceDirPicker;
    wxDirPicker* mDestinationDirPicker;
    wxButton* mButtonLoad;
    wxCheckBox* mSubFolders;
};

#endif // WXPANELSTART_H
