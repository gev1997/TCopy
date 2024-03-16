#include "wxPanelMain.h"
#include "../FileSyncApp.h"

wxPanelMain::wxPanelMain(wxFrame* parent)
    : wxPanelBase_{parent, {600, 500}}
    , mFileStaticBox{new wxFileStaticBox(this)}
    , mExtensionsStaticBox{new wxExtensionsStaticBox(this)}
    , mButtonBack{new wxButton(this, wxID_ANY, "Back", {10, 5}, {60, 25})}
    , mButtonUpdate{new wxButton(this, wxID_ANY, "Update", {515, 5}, {60, 25})}
    , mButtonCopy{new wxButton(this, wxID_ANY, "Copy", {420, 410}, {155, 40})}
{
    mButtonBack->Bind(wxEVT_BUTTON, &wxPanelMain::OnBackClicked, this);
    mButtonUpdate->Bind(wxEVT_BUTTON, &wxPanelMain::OnUpdateClicked, this);
    mButtonCopy->Bind(wxEVT_BUTTON, &wxPanelMain::OnCopyClicked, this);
    Bind(wxEVT_EXTENSION_FILTER, &wxPanelMain::OnExtensionFiltered, this);
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
{
    mApp.GetMainFrame().Load();
}

void wxPanelMain::OnCopyClicked(wxCommandEvent& event)
{
    const std::vector<int> checkedItems = mFileStaticBox->GetCheckedItems();

    if (!checkedItems.size())
    {
        // TODO: Error handling here
        return;
    }

    mApp.GetDB().CopyFiles(checkedItems);
}

void wxPanelMain::OnExtensionFiltered(wxExtensionFilterEvent& event)
{
    const std::string extension = event.GetExtension().ToStdString();
    const DB::FilterType filter = event.GetFilter();

    mApp.GetDB().Filter(extension, filter);
    mFileStaticBox->FillControlsData(mApp.GetDB().GetFiles());
}
