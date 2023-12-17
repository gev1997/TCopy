#pragma once

#include "File.h"

namespace DB
{

class Manager
{
public:
    Manager();
    ~Manager() = default;

    const fs::path& GetSourcePath() const;
    const fs::path& GetDestinationPath() const;
    const FileType& GetFiles() const;
    const ExtensionType& GetExtensions() const;
    void Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders);

private:
    template <typename Iter>
    void _Load();

private:
    fs::path mSourcePath;
    fs::path mDestinationPath;
    bool mSubFolders;
    FileType mFiles;
    ExtensionType mExtensions;
};

};  // namespace DB
