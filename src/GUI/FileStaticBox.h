#pragma once

#include "StaticBoxBase.h"

namespace GUI { class FileStaticBox; };

class GUI::FileStaticBox : public StaticBoxBase
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
};
