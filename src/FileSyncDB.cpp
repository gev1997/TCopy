#include "FileSyncDB.h"

FileSyncDB::FileSyncDB()
{}

const fs::path& FileSyncDB::GetSourcePath() const
{
    return mSourcePath;
}

const fs::path& FileSyncDB::GetDestinationPath() const
{
    return mDestinationPath;
}

void FileSyncDB::SetSourcePath(const fs::path& path)
{
    mSourcePath = path;
}

void FileSyncDB::SetDestinationPath(const fs::path& path)
{
    mDestinationPath = path;
}

void FileSyncDB::Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders)
{

}
