#ifndef WXPANELMAIN_H
#define WXPANELMAIN_H

#include <wx/panel.h>
#include <wx/frame.h>

class wxPanelMain : public wxPanel
{
public:
    wxPanelMain(wxFrame* parent);
    virtual ~wxPanelMain() = default;

    void Display(bool show);

private:
    const wxSize mSize;
};

#endif // WXPANELMAIN_H
