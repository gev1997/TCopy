#pragma once

#include <wx/statbox.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>

namespace GUI { class StaticBoxBase; };

class GUI::StaticBoxBase : public wxStaticBox
{
public:
    StaticBoxBase(wxWindow* parent, const wxPoint& pos, const wxSize& size);
    virtual ~StaticBoxBase() = default;

protected:
    wxCheckListBox* mCheckListBox;
    wxCheckBox* mSelectAll;
};
