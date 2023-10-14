#ifndef WXPANELSTART_H
#define WXPANELSTART_H

#include <wx/panel.h>
#include <wx/frame.h>

class wxPanelStart : public wxPanel
{
public:
    wxPanelStart(wxFrame* parent);
    virtual ~wxPanelStart() = default;

    void Display(bool show);

private:
    const wxSize mSize;
};

#endif // WXPANELSTART_H
