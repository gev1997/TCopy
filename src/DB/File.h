#pragma once

#include <wx/datetime.h>

namespace DB { class File; };

class DB::File
{
public:
    File(const fs::path& path);
    File(const File& file);
    ~File() = default;

    fs::path GetPath() const;
    std::string GetFileName() const;
    std::string GetExtension() const;
    std::string GetFormatName() const;

    bool operator<(const File& rhs) const;
    bool operator>(const File& rhs) const;
    bool operator==(const File& rhs) const;

private:
    const fs::path mPath;
    const wxDateTime mDateTime;
};
