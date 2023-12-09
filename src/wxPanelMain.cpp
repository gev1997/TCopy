#include "wxPanelMain.h"
#include "FileSyncApp.h"

wxPanelMain::wxPanelMain(wxFrame* parent)
    : wxPanelBase_{parent, {600, 500}}
    , mFileStaticBox{new wxFileStaticBox(this)}
{}
