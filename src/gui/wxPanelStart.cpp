#include "wxPanelStart.h"
#include "FileSyncApp.h"

wxPanelStart::wxPanelStart(wxFrame* parent)
    : wxPanelBase_{parent, {520, 250}}
    , mSourceDirPicker{new wxDirPicker(this, "Source", {10, 10}, {485, 30})}
    , mDestinationDirPicker{new wxDirPicker(this, "Destination", {10, 50}, {485, 30})}
    , mButtonLoad{new wxButton(this, wxID_ANY, "Load", {365, 160}, {130, 40})}
    , mSubFolders{new wxCheckBox(this, wxID_ANY, "Subfolders", {10, 90}, {90, 20})}
{
    FileSyncRegistery& registery = mApp.GetRegistery();

    mSourceDirPicker->SetPath(registery.QueryRegisteryValue(FileSyncRegistery::Key::SourceKey));
    mDestinationDirPicker->SetPath(registery.QueryRegisteryValue(FileSyncRegistery::Key::DestinationKey));

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

    mApp.GetDB().SetData(sourcePath, destinationPath, mSubFolders->IsChecked());
    mApp.GetRegistery().WriteRegisteryValue();
    mApp.GetMainFrame().Load();
}
