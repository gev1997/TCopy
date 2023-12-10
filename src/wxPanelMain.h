#pragma once

#include <wx/button.h>

#include "wxPanelBase.h"
#include "wxFileStaticBox.h"

class wxPanelMain : public wxPanelBase_
{
public:
    wxPanelMain(wxFrame* parent);
    virtual ~wxPanelMain() = default;

private:
    void OnBackClicked(wxCommandEvent& event);

private:
    wxFileStaticBox* mFileStaticBox;
    wxButton* mButtonBack;
};
