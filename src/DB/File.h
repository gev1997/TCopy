#pragma once

#include <wx/datetime.h>

namespace DB
{

class File
{
public:
    File(const fs::path& path);
    File(const File& file);
    ~File() = default;

    std::string GetFileName() const;
    std::string GetExtension() const;
    // fs::path GetParentPath();

    bool operator<(const File& rhs) const;
    bool operator>(const File& rhs) const;
    bool operator==(const File& rhs) const;

private:
    const fs::path mPath;
    const wxDateTime mDateTime;
};

}; // namespace DB
