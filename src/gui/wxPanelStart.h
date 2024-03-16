#pragma once

#include <wx/button.h>
#include <wx/checkbox.h>

#include "wxPanelBase.h"
#include "wxDirPicker.h"

namespace gui { class PanelStart; };

class gui::PanelStart : public PanelBase
{
public:
    PanelStart(wxFrame* parent);
    virtual ~PanelStart() = default;

private:
    void OnLoadClicked(wxCommandEvent& event);

private:
    wxDirPicker* mSourceDirPicker;
    wxDirPicker* mDestinationDirPicker;
    wxButton* mButtonLoad;
    wxCheckBox* mSubFolders;
};
