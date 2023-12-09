#pragma once

#include "wxPanelBase.h"
#include "wxFileStaticBox.h"

class wxPanelMain : public wxPanelBase_
{
public:
    wxPanelMain(wxFrame* parent);
    virtual ~wxPanelMain() = default;

private:
    wxFileStaticBox* mFileStaticBox;
};
