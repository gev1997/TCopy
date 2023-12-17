#pragma once

#include <wx/statbox.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>

class wxFileStaticBox : public wxStaticBox
{
public:
    wxFileStaticBox(wxWindow* parent);
    virtual ~wxFileStaticBox() = default;

    void FillControlsData(const DB::FileType& files);

private:
    wxCheckListBox* mFileListBox;
    wxCheckBox* mSelectAll;
};
