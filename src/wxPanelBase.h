#ifndef WXPANELBASE_H
#define WXPANELBASE_H

#include <wx/panel.h>
#include <wx/frame.h>

class wxPanelBase_ : public wxPanel
{
public:
    wxPanelBase_(wxFrame* parent, const wxSize& size);
    virtual ~wxPanelBase_() = default;

    void Display(bool show);

protected:
    wxSize mSize;
};

#endif // WXPANELBASE_H
