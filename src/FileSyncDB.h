#ifndef TCOPYDB_H
#define TCOPYDB_H

#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class TCopyDB
{
public:
    TCopyDB();
    ~TCopyDB() = default;

    const fs::path& GetSourcePath() const;
    const fs::path& GetDestinationPath() const;
    void SetSourcePath(const fs::path& path);
    void SetDestinationPath(const fs::path& path);
    void Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders);

private:
    fs::path mSourcePath;
    fs::path mDestinationPath;
};

#endif // TCOPYDB_H
