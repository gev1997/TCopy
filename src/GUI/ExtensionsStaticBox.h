#pragma once

#include <wx/checklst.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>

#include "StaticBoxBase.h"

namespace GUI { class ExtensionsStaticBox; };

class GUI::ExtensionsStaticBox : public StaticBoxBase
{
public:
    ExtensionsStaticBox(wxWindow* parent);
    virtual ~ExtensionsStaticBox() = default;

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
