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
    void Filter(const std::list<std::string>& extensions);
    void SetData(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders);
    void Load();

private:
    template <typename Iter>
    void _Load();

private:
    fs::path mSourcePath;
    fs::path mDestinationPath;
    bool mSubFolders;
    FileType mFiles;
    FileType mVisibleFiles;
    ExtensionType mExtensions;
};

};  // namespace DB
