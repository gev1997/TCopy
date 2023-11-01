#include "wxPanelStart.h"

wxPanelStart::wxPanelStart(wxFrame* parent)
    : wxPanelBase_{parent, {520, 250}}
    , mEditSource{new wxTextCtrl(this, wxID_ANY, "", {10, 10}, {405, 30})}
    , mEditDestination{new wxTextCtrl(this, wxID_ANY, "", {10, 50}, {405, 30})}
    , mButtonSource{new wxDirDlgButton(this, mEditSource, "Source", {425, 10}, {70, 30})}
    , mButtonDestination{new wxDirDlgButton(this, mEditDestination, "Destination", {425, 50}, {70, 30})}
    , mButtonLoad{new wxButton(this, wxID_ANY, "Load", {365, 160}, {130, 40})}
    , mSubFolders{new wxCheckBox(this, wxID_ANY, "Subfolders", {10, 90}, {90, 20})}
{
    mButtonLoad->Bind(wxEVT_BUTTON, &wxPanelStart::ButtonLoadClicked, this);
}

void wxPanelStart::ButtonLoadClicked(wxCommandEvent& event)
{}
