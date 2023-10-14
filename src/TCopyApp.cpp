#include <iostream>

#include "TCopyApp.h"

TCopyApp::TCopyApp()
    : mFrameContainer{new wxMainFrame}
{}

bool TCopyApp::OnInit()
{
    assert(mFrameContainer);
    mFrameContainer->Show();
    mFrameContainer->Centre();

    return true;
}

wxIMPLEMENT_APP(TCopyApp);
