#ifndef WXPANELBASE_H
#define WXPANELBASE_H

#include <wx/panel.h>
#include <wx/frame.h>

class TCopyApp;

class wxPanelBase_ : public wxPanel
{
public:
    wxPanelBase_(wxFrame* parent, const wxSize& size);
    virtual ~wxPanelBase_() = default;

    void Display(bool show);

protected:
    TCopyApp& mApp;
    wxSize mSize;
};

#endif // WXPANELBASE_H
