#include "wxExtensionsStaticBox.h"
#include "FileSyncEvent.h"

wxExtensionsStaticBox::wxExtensionsStaticBox(wxWindow* parent)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, {420, 30}, {155, 230}}
    , mExtensionsListBox{new wxCheckListBox(this, wxID_ANY, {10, 55}, {135, 165})}
    , mExtensionsSearchCtrl{new wxTextCtrl(this, wxID_ANY, wxEmptyString, {10, 30}, {135, 20}, wxTE_PROCESS_ENTER)}
    , mSelectAll{new wxCheckBox(this, wxID_ANY, "Select All", {13, 10}, {70, 20}, wxCHK_3STATE)}
{
    mExtensionsSearchCtrl->SetHint("Search");

    mExtensionsListBox->Bind(wxEVT_CHECKLISTBOX, &wxExtensionsStaticBox::OnExtensionChecked, this);
    mExtensionsSearchCtrl->Bind(wxEVT_TEXT, &wxExtensionsStaticBox::OnExtensionSearch, this);
    mExtensionsSearchCtrl->Bind(wxEVT_TEXT_ENTER, &wxExtensionsStaticBox::OnExtensionSearchEnter, this);
    mSelectAll->Bind(wxEVT_CHECKBOX, &wxExtensionsStaticBox::OnExtensionAllChecked, this);
}

void wxExtensionsStaticBox::FillControlsData(const DB::ExtensionType& extensions)
{
    mExtensionsListBox->Clear();
    mExtensionsSearchCtrl->ChangeValue(wxEmptyString);
    mSelectAll->Set3StateValue(wxCheckBoxState::wxCHK_CHECKED);

    wxArrayString extensionItems;
    std::ranges::copy(extensions.begin(), extensions.end(), std::back_inserter(extensionItems));
    mExtensionsListBox->InsertItems(extensionItems, 0);
    CheckAll(true);
}

void wxExtensionsStaticBox::CheckAll(bool check)
{
    for (int i = 0; i < mExtensionsListBox->GetCount(); ++i)
        mExtensionsListBox->Check(i, check);
}

void wxExtensionsStaticBox::UpdateSelectAllState()
{
    wxArrayInt checkedItems;
    mExtensionsListBox->GetCheckedItems(checkedItems);
    
    wxCheckBoxState state;

    if (checkedItems.GetCount() == mExtensionsListBox->GetCount())
        state = wxCheckBoxState::wxCHK_CHECKED;
    else if (!checkedItems.GetCount())
        state = wxCheckBoxState::wxCHK_UNCHECKED;
    else
        state = wxCheckBoxState::wxCHK_UNDETERMINED;

    mSelectAll->Set3StateValue(state);
}

void wxExtensionsStaticBox::OnExtensionChecked(wxCommandEvent& event)
{
    unsigned int item = event.GetInt();
    bool isChecked = mExtensionsListBox->IsChecked(item);

    wxExtensionFilterEvent newEvent;
    newEvent.SetExtension(event.GetString());
    newEvent.SetFilter(isChecked ? DB::FilterType::Insert : DB::FilterType::Remove);
    GetParent()->GetEventHandler()->ProcessEvent(newEvent);
    
    UpdateSelectAllState();
}

void wxExtensionsStaticBox::OnExtensionAllChecked(wxCommandEvent& event)
{
    bool isChecked = event.IsChecked();
    CheckAll(isChecked);

    wxExtensionFilterEvent newEvent;
    newEvent.SetFilter(isChecked ? DB::FilterType::Reset : DB::FilterType::Clear);
    GetParent()->GetEventHandler()->ProcessEvent(newEvent);
}

void wxExtensionsStaticBox::OnExtensionSearch(wxCommandEvent& event)
{
    wxString searchText = event.GetString();
    
    if (!searchText)
        return;

    if (searchText[0] != '.')
        searchText.Prepend(".");

    int item = wxNOT_FOUND;

    for (int i = 0; i < mExtensionsListBox->GetCount(); ++i)
    {
        if (mExtensionsListBox->GetString(i) == searchText)
        {
            item = i;
            break;
        }
    }

    mExtensionsListBox->SetSelection(item);
}

void wxExtensionsStaticBox::OnExtensionSearchEnter(wxCommandEvent& event)
{
    int item = mExtensionsListBox->GetSelection();

    if (item == wxNOT_FOUND)
        return;

    bool isChecked = mExtensionsListBox->IsChecked(item);
    mExtensionsListBox->Check(item, !isChecked);

    wxCommandEvent commandEvent(wxEVT_CHECKLISTBOX);
    commandEvent.SetInt(item);
    commandEvent.SetString(mExtensionsListBox->GetString(item));
    mExtensionsListBox->GetEventHandler()->ProcessEvent(commandEvent);
}
