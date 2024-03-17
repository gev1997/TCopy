#pragma once

#include <wx/statbox.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>

namespace GUI { class FileStaticBox; };

class GUI::FileStaticBox : public wxStaticBox
{
public:
    FileStaticBox(wxWindow* parent);
    virtual ~FileStaticBox() = default;

    void FillControlsData(const DB::FileType& files);
    std::vector<int> GetCheckedItems() const;

private:
    void CheckAll(bool check);
    void UpdateSelectAllState();
    void OnFileChecked(wxCommandEvent& event);
    void OnFileDoubleClicked(wxCommandEvent& event);
    void OnFileAllChecked(wxCommandEvent& event);

private:
    wxCheckListBox* mFileListBox;
    wxCheckBox* mSelectAll;
};
