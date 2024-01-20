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
    std::vector<int> GetCheckedItems() const;

private:
    void CheckAll(bool check);
    void UpdateSelectAllState();
    void OnFileChecked(wxCommandEvent& event);
    void OnFileAllChecked(wxCommandEvent& event);

private:
    wxCheckListBox* mFileListBox;
    wxCheckBox* mSelectAll;
};
