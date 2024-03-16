#pragma once

#include <wx/panel.h>
#include <wx/frame.h>

class FileSyncApp;

namespace gui { class PanelBase; };

class gui::PanelBase : public wxPanel
{
public:
    PanelBase(wxFrame* parent, const wxSize& size);
    virtual ~PanelBase() = default;

    void Display(bool show);

protected:
    FileSyncApp& mApp;
};
