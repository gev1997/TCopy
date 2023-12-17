#include "wxFileStaticBox.h"

wxFileStaticBox::wxFileStaticBox(wxWindow* parent)
    : wxStaticBox{parent, wxID_ANY, wxEmptyString, {10, 30}, {330, 420}}
    , mFileListBox{new wxCheckListBox(this, wxID_ANY, {10, 30}, {310, 380})}
    , mSelectAll{new wxCheckBox(this, wxID_ANY, "Select All", {13, 10}, {90, 20}, wxCHK_3STATE)}
{}
