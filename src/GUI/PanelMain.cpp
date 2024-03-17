#include "PanelMain.h"
#include "../FileSyncApp.h"

GUI::PanelMain::PanelMain(wxFrame* parent)
    : PanelBase{parent, {600, 500}}
    , mFileStaticBox{new FileStaticBox(this)}
    , mExtensionsStaticBox{new ExtensionsStaticBox(this)}
    , mButtonBack{new wxButton(this, wxID_ANY, "Back", {10, 5}, {60, 25})}
    , mButtonUpdate{new wxButton(this, wxID_ANY, "Update", {515, 5}, {60, 25})}
    , mButtonCopy{new wxButton(this, wxID_ANY, "Copy", {420, 410}, {155, 40})}
{
    mButtonBack->Bind(wxEVT_BUTTON, &PanelMain::OnBackClicked, this);
    mButtonUpdate->Bind(wxEVT_BUTTON, &PanelMain::OnUpdateClicked, this);
    mButtonCopy->Bind(wxEVT_BUTTON, &PanelMain::OnCopyClicked, this);
    Bind(wxEVT_EXTENSION_FILTER, &PanelMain::OnExtensionFiltered, this);
}

void GUI::PanelMain::FillControlsData()
{
    mFileStaticBox->FillControlsData(mApp.GetDB().GetFiles());
    mExtensionsStaticBox->FillControlsData(mApp.GetDB().GetExtensions());
}

void GUI::PanelMain::OnBackClicked(wxCommandEvent& event)
{
    mApp.GetMainFrame().Back();
}

void GUI::PanelMain::OnUpdateClicked(wxCommandEvent& event)
{
    mApp.GetMainFrame().Load();
}

void GUI::PanelMain::OnCopyClicked(wxCommandEvent& event)
{
    const std::vector<int> checkedItems = mFileStaticBox->GetCheckedItems();

    if (!checkedItems.size())
    {
        // TODO: Error handling here
        return;
    }

    mApp.GetDB().CopyFiles(checkedItems);
}

void GUI::PanelMain::OnExtensionFiltered(ExtensionFilterEvent& event)
{
    const std::string extension = event.GetExtension().ToStdString();
    const DB::FilterType filter = event.GetFilter();

    mApp.GetDB().Filter(extension, filter);
    mFileStaticBox->FillControlsData(mApp.GetDB().GetFiles());
}
