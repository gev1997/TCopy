#pragma once

#include <wx/statbox.h>
#include <wx/checklst.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>

class wxExtensionsStaticBox : public wxStaticBox
{
public:
    wxExtensionsStaticBox(wxWindow* parent);
    virtual ~wxExtensionsStaticBox() = default;

    void FillControlsData(const DB::ExtensionType& extensions);

private:
    void CheckAll(bool check);
    void UpdateSelectAllState();
    void OnExtensionChecked(wxCommandEvent& event);
    void OnExtensionAllChecked(wxCommandEvent& event);
    void OnExtensionSearch(wxCommandEvent& event);
    void OnExtensionSearchEnter(wxCommandEvent& event);

private:
    wxCheckListBox* mExtensionsListBox;
    wxTextCtrl* mExtensionsSearchCtrl;
    wxCheckBox* mSelectAll;
};
