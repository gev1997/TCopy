#pragma once

#include <wx/statbox.h>
#include <wx/checklst.h>
#include <wx/srchctrl.h>
#include <wx/checkbox.h>

class wxExtensionsStaticBox : public wxStaticBox
{
public:
    wxExtensionsStaticBox(wxWindow* parent);
    virtual ~wxExtensionsStaticBox() = default;

    void FillControlsData(const DB::ExtensionType& files);

private:
    wxCheckListBox* mExtensionsListBox;
    wxSearchCtrl* mExtensionsSearchCtrl;
    wxCheckBox* mSelectAll;
};
