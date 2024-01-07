#include "wxExtensionsStaticBox.h"

wxExtensionsStaticBox::wxExtensionsStaticBox(wxWindow* parent)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, {420, 30}, {155, 230}}
    , mExtensionsListBox{new wxCheckListBox(this, wxID_ANY, {10, 55}, {135, 165})}
    , mExtensionsSearchCtrl{new wxTextCtrl(this, wxID_ANY, wxEmptyString, {10, 30}, {135, 20}, wxTE_PROCESS_ENTER)}
    , mSelectAll{new wxCheckBox(this, wxID_ANY, "Select All", {13, 10}, {70, 20}, wxCHK_3STATE)}
{
    mExtensionsSearchCtrl->SetHint("Search");
}

void wxExtensionsStaticBox::FillControlsData(const DB::ExtensionType& extensions)
{
    mExtensionsListBox->Clear();
    mExtensionsSearchCtrl->ChangeValue(wxEmptyString);
    mSelectAll->Set3StateValue(wxCheckBoxState::wxCHK_CHECKED);

    wxArrayString extensionItems;
    std::ranges::copy(extensions.begin(), extensions.end(), std::back_inserter(extensionItems));
    mExtensionsListBox->InsertItems(extensionItems, 0);
}
