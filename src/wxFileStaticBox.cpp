#include "wxFileStaticBox.h"

wxFileStaticBox::wxFileStaticBox(wxWindow* parent)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, {10, 30}, {400, 420}}
    , mFileListBox{new wxCheckListBox(this, wxID_ANY, {10, 30}, {380, 380})}
    , mSelectAll{new wxCheckBox(this, wxID_ANY, "Select All", {13, 10}, {90, 20}, wxCHK_3STATE)}
{}

void wxFileStaticBox::FillControlsData(const DB::FileType& files)
{
    mFileListBox->Clear();
    mSelectAll->Set3StateValue(wxCheckBoxState::wxCHK_UNCHECKED);

    wxArrayString fileItems;
    std::ranges::transform(files, std::back_inserter(fileItems), &DB::File::GetFormatName);
    mFileListBox->InsertItems(fileItems, 0);
}
