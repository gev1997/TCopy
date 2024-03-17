#pragma once

#include <wx/button.h>

#include "wxPanelBase.h"
#include "wxFileStaticBox.h"
#include "wxExtensionsStaticBox.h"
#include "ExtensionFilterEvent.h"

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
    void OnExtensionFiltered(ExtensionFilterEvent& event);
    void OnCopyClicked(wxCommandEvent& event);

private:
    FileStaticBox* mFileStaticBox;
    ExtensionsStaticBox* mExtensionsStaticBox;
    wxButton* mButtonBack;
    wxButton* mButtonUpdate;
    wxButton* mButtonCopy;
};
