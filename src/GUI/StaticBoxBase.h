#pragma once

#include <wx/statbox.h>

namespace GUI { class StaticBoxBase; };

class GUI::StaticBoxBase : public wxStaticBox
{
public:
    StaticBoxBase(wxWindow* parent, const wxPoint& pos, const wxSize& size);
    virtual ~StaticBoxBase() = default;
};
