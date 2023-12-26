#include "wxPanelMain.h"
#include "FileSyncApp.h"

wxPanelMain::wxPanelMain(wxFrame* parent)
    : wxPanelBase_{parent, {600, 500}}
    , mFileStaticBox{new wxFileStaticBox(this)}
    , mExtensionsStaticBox{new wxExtensionsStaticBox(this)}
    , mButtonBack{new wxButton(this, wxID_ANY, "Back", {10, 5}, {60, 25})}
    , mButtonUpdate{new wxButton(this, wxID_ANY, "Update", {515, 5}, {60, 25})}
{
    mButtonBack->Bind(wxEVT_BUTTON, &wxPanelMain::OnBackClicked, this);
    mButtonUpdate->Bind(wxEVT_BUTTON, &wxPanelMain::OnUpdateClicked, this);
}

void wxPanelMain::FillControlsData()
{
    mFileStaticBox->FillControlsData(mApp.GetDB().GetFiles());
    mExtensionsStaticBox->FillControlsData(mApp.GetDB().GetExtensions());
}

void wxPanelMain::OnBackClicked(wxCommandEvent& event)
{
    mApp.GetMainFrame().Back();
}

void wxPanelMain::OnUpdateClicked(wxCommandEvent& event)
{}
