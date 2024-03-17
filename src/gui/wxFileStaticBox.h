#pragma once

#include <wx/statbox.h>
#include <wx/checklst.h>
#include <wx/checkbox.h>

namespace gui { class FileStaticBox; };

class gui::FileStaticBox : public wxStaticBox
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
