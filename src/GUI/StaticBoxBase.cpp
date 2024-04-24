#include "StaticBoxBase.h"

GUI::StaticBoxBase::StaticBoxBase(wxWindow* parent, const wxPoint& pos, const wxSize& size)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, pos, size}
    , mSelectAll{new wxCheckBox()}
    , mCheckListBox{new wxCheckListBox()}
{}

void GUI::StaticBoxBase::CheckAll(bool check)
{
    for (int i = 0; i < mCheckListBox->GetCount(); ++i)
        mCheckListBox->Check(i, check);
}

void GUI::StaticBoxBase::UpdateSelectAllState()
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
