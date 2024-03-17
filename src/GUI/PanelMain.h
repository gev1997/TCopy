#pragma once

#include <wx/button.h>

#include "PanelBase.h"
#include "FileStaticBox.h"
#include "ExtensionsStaticBox.h"
#include "ExtensionFilterEvent.h"

namespace GUI { class PanelMain; };

class GUI::PanelMain : public PanelBase
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
