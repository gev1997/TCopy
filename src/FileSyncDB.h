#ifndef FILESYNCDB_H
#define FILESYNCDB_H

#include <string>
#include <filesystem>

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
    fs::path mSourcePath;
    fs::path mDestinationPath;
};

};  // namespace DB

#endif // FILESYNCDB_H
