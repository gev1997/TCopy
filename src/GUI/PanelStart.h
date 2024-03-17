#pragma once

#include <wx/button.h>
#include <wx/checkbox.h>

#include "PanelBase.h"
#include "DirPicker.h"

namespace GUI { class PanelStart; };

class GUI::PanelStart : public PanelBase
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
