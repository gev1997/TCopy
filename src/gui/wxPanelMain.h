#pragma once

#include <wx/button.h>

#include "wxPanelBase.h"
#include "wxFileStaticBox.h"
#include "wxExtensionsStaticBox.h"
#include "FileSyncEvent.h"

namespace gui { class PanelMain; };

class gui::PanelMain : public PanelBase
{
public:
    PanelMain(wxFrame* parent);
    virtual ~PanelMain() = default;

    void FillControlsData();

private:
    void OnBackClicked(wxCommandEvent& event);
    void OnUpdateClicked(wxCommandEvent& event);
    void OnExtensionFiltered(wxExtensionFilterEvent& event);
    void OnCopyClicked(wxCommandEvent& event);

private:
    wxFileStaticBox* mFileStaticBox;
    wxExtensionsStaticBox* mExtensionsStaticBox;
    wxButton* mButtonBack;
    wxButton* mButtonUpdate;
    wxButton* mButtonCopy;
};
