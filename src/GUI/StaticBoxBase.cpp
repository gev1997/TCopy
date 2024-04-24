#include "StaticBoxBase.h"

GUI::StaticBoxBase::StaticBoxBase(wxWindow* parent, const wxPoint& pos, const wxSize& size)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, pos, size}
    , mSelectAll{new wxCheckBox()}
    , mCheckListBox{new wxCheckListBox()}
{}
