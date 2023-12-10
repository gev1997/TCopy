#pragma once

#include <set>
#include <string>
#include <filesystem>

#include "File.h"

namespace fs = std::filesystem;

namespace DB
{

class Manager
{
public:
    Manager();
    ~Manager() = default;

    const fs::path& GetSourcePath() const;
    const fs::path& GetDestinationPath() const;
    void Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders);

private:
    template <typename Iter>
    void _Load();

private:
    fs::path mSourcePath;
    fs::path mDestinationPath;
    bool mSubFolders;
    std::multiset<File> mFiles;
    std::set<std::string> mExtensions;
};

};  // namespace DB
