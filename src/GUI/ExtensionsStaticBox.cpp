#include "ExtensionsStaticBox.h"
#include "ExtensionFilterEvent.h"

GUI::ExtensionsStaticBox::ExtensionsStaticBox(wxWindow* parent)
    : StaticBoxBase{parent, {420, 30}, {155, 230}}
    , mExtensionsSearchCtrl{new wxTextCtrl(this, wxID_ANY, wxEmptyString, {10, 30}, {135, 20}, wxTE_PROCESS_ENTER)}
{
    mCheckListBox->Create(this, wxID_ANY, {10, 55}, {135, 165});
    mSelectAll->Create(this, wxID_ANY, "Select All", {13, 10}, {70, 20}, wxCHK_3STATE);

    mExtensionsSearchCtrl->SetHint("Search");

    mCheckListBox->Bind(wxEVT_CHECKLISTBOX, &ExtensionsStaticBox::OnExtensionChecked, this);
    mExtensionsSearchCtrl->Bind(wxEVT_TEXT, &ExtensionsStaticBox::OnExtensionSearch, this);
    mExtensionsSearchCtrl->Bind(wxEVT_TEXT_ENTER, &ExtensionsStaticBox::OnExtensionSearchEnter, this);
    mSelectAll->Bind(wxEVT_CHECKBOX, &ExtensionsStaticBox::OnExtensionAllChecked, this);
}

void GUI::ExtensionsStaticBox::FillControlsData(const DB::ExtensionType& extensions)
{
    mCheckListBox->Clear();
    mExtensionsSearchCtrl->ChangeValue(wxEmptyString);
    mSelectAll->Set3StateValue(wxCheckBoxState::wxCHK_CHECKED);

    wxArrayString extensionItems;
    std::ranges::copy(extensions.begin(), extensions.end(), std::back_inserter(extensionItems));
    mCheckListBox->InsertItems(extensionItems, 0);
    CheckAll(true);
}

void GUI::ExtensionsStaticBox::OnExtensionChecked(wxCommandEvent& event)
{
    unsigned int item = event.GetInt();
    bool isChecked = mCheckListBox->IsChecked(item);

    ExtensionFilterEvent newEvent;
    newEvent.SetExtension(event.GetString());
    newEvent.SetFilter(isChecked ? DB::FilterType::Insert : DB::FilterType::Remove);
    GetParent()->GetEventHandler()->ProcessEvent(newEvent);
    
    UpdateCheckAllState();
}

void GUI::ExtensionsStaticBox::OnExtensionAllChecked(wxCommandEvent& event)
{
    bool isChecked = event.IsChecked();
    CheckAll(isChecked);

    ExtensionFilterEvent newEvent;
    newEvent.SetFilter(isChecked ? DB::FilterType::Reset : DB::FilterType::Clear);
    GetParent()->GetEventHandler()->ProcessEvent(newEvent);
}

void GUI::ExtensionsStaticBox::OnExtensionSearch(wxCommandEvent& event)
{
    wxString searchText = event.GetString();
    
    if (!searchText)
        return;

    if (searchText[0] != '.')
        searchText.Prepend(".");

    int item = wxNOT_FOUND;

    for (int i = 0; i < mCheckListBox->GetCount(); ++i)
    {
        if (mCheckListBox->GetString(i) == searchText)
        {
            item = i;
            break;
        }
    }

    mCheckListBox->SetSelection(item);
}

void GUI::ExtensionsStaticBox::OnExtensionSearchEnter(wxCommandEvent& event)
{
    int item = mCheckListBox->GetSelection();

    if (item == wxNOT_FOUND)
        return;

    bool isChecked = mCheckListBox->IsChecked(item);
    mCheckListBox->Check(item, !isChecked);

    wxCommandEvent commandEvent(wxEVT_CHECKLISTBOX);
    commandEvent.SetInt(item);
    commandEvent.SetString(mCheckListBox->GetString(item));
    mCheckListBox->GetEventHandler()->ProcessEvent(commandEvent);
}
