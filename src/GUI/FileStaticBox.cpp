#include <wx/utils.h>

#include "FileStaticBox.h"

GUI::FileStaticBox::FileStaticBox(wxWindow* parent)
    : StaticBoxBase{parent, {10, 30}, {400, 420}}
{
    mCheckListBox->Create(this, wxID_ANY, {10, 30}, {380, 380});
    mSelectAll->Create(this, wxID_ANY, "Select All", {13, 10}, {90, 20}, wxCHK_3STATE);

    mCheckListBox->Bind(wxEVT_CHECKLISTBOX, &FileStaticBox::OnFileChecked, this);
    mCheckListBox->Bind(wxEVT_LISTBOX_DCLICK, &FileStaticBox::OnFileDoubleClicked, this);
    mSelectAll->Bind(wxEVT_CHECKBOX, &FileStaticBox::OnFileAllChecked, this);
}

void GUI::FileStaticBox::FillControlsData(const DB::FileType& files)
{
    mCheckListBox->Clear();
    mSelectAll->Set3StateValue(wxCheckBoxState::wxCHK_UNCHECKED);

    if (!files.size())
        return;

    wxArrayString fileItems;
    std::ranges::transform(files, std::back_inserter(fileItems), &DB::File::GetFormatName);
    mCheckListBox->InsertItems(fileItems, 0);
}

std::vector<int> GUI::FileStaticBox::GetCheckedItems() const
{
    wxArrayInt checkedItems;
    mCheckListBox->GetCheckedItems(checkedItems);

    return {checkedItems.begin(), checkedItems.end()};
}

void GUI::FileStaticBox::CheckAll(bool check)
{
    for (int i = 0; i < mCheckListBox->GetCount(); ++i)
        mCheckListBox->Check(i, check);
}

void GUI::FileStaticBox::UpdateSelectAllState()
{
    wxArrayInt checkedItems;
    mCheckListBox->GetCheckedItems(checkedItems);
    
    wxCheckBoxState state;

    if (checkedItems.GetCount() == mCheckListBox->GetCount())
        state = wxCheckBoxState::wxCHK_CHECKED;
    else if (!checkedItems.GetCount())
        state = wxCheckBoxState::wxCHK_UNCHECKED;
    else
        state = wxCheckBoxState::wxCHK_UNDETERMINED;

    mSelectAll->Set3StateValue(state);
}

void GUI::FileStaticBox::OnFileChecked(wxCommandEvent& event)
{
    UpdateSelectAllState();
}

void GUI::FileStaticBox::OnFileDoubleClicked(wxCommandEvent& event)
{
    if (wxGetKeyState(WXK_CONTROL))
    {
        for (int i = event.GetInt(); i < mCheckListBox->GetCount(); ++i)
            mCheckListBox->Check(i, true);
    }
    else
    {
        for (int i = event.GetInt(); i >= 0; --i)
            mCheckListBox->Check(i, true);
    }

    UpdateSelectAllState();
}

void GUI::FileStaticBox::OnFileAllChecked(wxCommandEvent& event)
{
    bool isChecked = event.IsChecked();
    CheckAll(isChecked);
}
