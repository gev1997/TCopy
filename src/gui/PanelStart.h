#pragma once

#include <wx/button.h>
#include <wx/checkbox.h>

#include "PanelBase.h"
#include "DirPicker.h"

namespace gui { class PanelStart; };

class gui::PanelStart : public PanelBase
{
public:
    PanelStart(wxFrame* parent);
    virtual ~PanelStart() = default;

private:
    void OnLoadClicked(wxCommandEvent& event);

private:
    DirPicker* mSourceDirPicker;
    DirPicker* mDestinationDirPicker;
    wxButton* mButtonLoad;
    wxCheckBox* mSubFolders;
};
