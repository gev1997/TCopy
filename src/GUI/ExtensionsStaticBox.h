#pragma once

#include <wx/textctrl.h>

#include "StaticBoxBase.h"

namespace GUI { class ExtensionsStaticBox; };

class GUI::ExtensionsStaticBox : public StaticBoxBase
{
public:
    ExtensionsStaticBox(wxWindow* parent);
    virtual ~ExtensionsStaticBox() = default;

    void FillControlsData(const DB::ExtensionType& extensions);

private:
    void OnExtensionChecked(wxCommandEvent& event);
    void OnExtensionAllChecked(wxCommandEvent& event);
    void OnExtensionSearch(wxCommandEvent& event);
    void OnExtensionSearchEnter(wxCommandEvent& event);

private:
    wxTextCtrl* mExtensionsSearchCtrl;
};
