#ifndef MANAGER_H
#define MANAGER_H

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
    void SetSourcePath(const fs::path& path);
    void SetDestinationPath(const fs::path& path);
    void Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders);

private:
    template <typename Iter>
    void _Load();

private:
    fs::path mSourcePath;
    fs::path mDestinationPath;
    bool mSubFolders;
    std::set<File> mFiles;
    std::set<std::string> mExtensions;
};

};  // namespace DB

#endif // MANAGER_H
