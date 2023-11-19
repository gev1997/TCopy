#include "wxPanelStart.h"
#include "FileSyncApp.h"

wxPanelStart::wxPanelStart(wxFrame* parent)
    : wxPanelBase_{parent, {520, 250}}
    , mSourceDirPicker{new wxDirPicker(this, "Source", {10, 10}, {485, 30})}
    , mDestinationDirPicker{new wxDirPicker(this, "Destination", {10, 50}, {485, 30})}
    , mButtonLoad{new wxButton(this, wxID_ANY, "Load", {365, 160}, {130, 40})}
    , mSubFolders{new wxCheckBox(this, wxID_ANY, "Subfolders", {10, 90}, {90, 20})}
{
    mButtonLoad->Bind(wxEVT_BUTTON, &wxPanelStart::OnLoadClicked, this);
}

void wxPanelStart::OnLoadClicked(wxCommandEvent& event)
{
    if (!mSourceDirPicker->IsDirectory() || !mDestinationDirPicker->IsDirectory())
    {
        // TODO: Error handling here
        return;
    }

    const std::string sourcePath = mSourceDirPicker->GetTextCtrlValue().ToStdString();
    const std::string destinationPath = mDestinationDirPicker->GetTextCtrlValue().ToStdString();

    // TODO: Maybe need to check Load() fail here ?
    mApp.GetDB()->Load(sourcePath, destinationPath, mSubFolders->IsChecked());

    mApp.GetMainFrame()->Display(wxMainFrame::Panel::Main);
}
