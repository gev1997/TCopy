#include "wxFileStaticBox.h"

wxFileStaticBox::wxFileStaticBox(wxWindow* parent)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, {10, 30}, {400, 420}}
    , mFileListBox{new wxCheckListBox(this, wxID_ANY, {10, 30}, {380, 380})}
    , mSelectAll{new wxCheckBox(this, wxID_ANY, "Select All", {13, 10}, {90, 20}, wxCHK_3STATE)}
{
    mFileListBox->Bind(wxEVT_CHECKLISTBOX, &wxFileStaticBox::OnFileChecked, this);
    mSelectAll->Bind(wxEVT_CHECKBOX, &wxFileStaticBox::OnFileAllChecked, this);
}

void wxFileStaticBox::FillControlsData(const DB::FileType& files)
{
    mFileListBox->Clear();
    mSelectAll->Set3StateValue(wxCheckBoxState::wxCHK_UNCHECKED);

    if (!files.size())
        return;

    wxArrayString fileItems;
    std::ranges::transform(files, std::back_inserter(fileItems), &DB::File::GetFormatName);
    mFileListBox->InsertItems(fileItems, 0);
}

void wxFileStaticBox::CheckAll(bool check)
{
    for (int i = 0; i < mFileListBox->GetCount(); ++i)
        mFileListBox->Check(i, check);
}

void wxFileStaticBox::UpdateSelectAllState()
{
    wxArrayInt checkedItems;
    mFileListBox->GetCheckedItems(checkedItems);
    
    wxCheckBoxState state;

    if (checkedItems.GetCount() == mFileListBox->GetCount())
        state = wxCheckBoxState::wxCHK_CHECKED;
    else if (!checkedItems.GetCount())
        state = wxCheckBoxState::wxCHK_UNCHECKED;
    else
        state = wxCheckBoxState::wxCHK_UNDETERMINED;

    mSelectAll->Set3StateValue(state);
}

void wxFileStaticBox::OnFileChecked(wxCommandEvent& event)
{
    unsigned int item = event.GetInt();
    bool isChecked = mFileListBox->IsChecked(item);
    
    UpdateSelectAllState();
}

void wxFileStaticBox::OnFileAllChecked(wxCommandEvent& event)
{
    bool isChecked = event.IsChecked();
    CheckAll(isChecked);
}
