#pragma once

#include <wx/button.h>

#include "wxPanelBase.h"
#include "wxFileStaticBox.h"
#include "wxExtensionsStaticBox.h"
#include "FileSyncEvent.h"

class wxPanelMain : public wxPanelBase_
{
public:
    wxPanelMain(wxFrame* parent);
    virtual ~wxPanelMain() = default;

    void FillControlsData();

private:
    void OnBackClicked(wxCommandEvent& event);
    void OnUpdateClicked(wxCommandEvent& event);
    void OnExtensionFiltered(wxExtensionFilterEvent& event);

private:
    wxFileStaticBox* mFileStaticBox;
    wxExtensionsStaticBox* mExtensionsStaticBox;
    wxButton* mButtonBack;
    wxButton* mButtonUpdate;
};
