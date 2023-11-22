#include "FileSyncDB.h"

DB::Manager::Manager()
{}

const fs::path& DB::Manager::GetSourcePath() const
{
    return mSourcePath;
}

const fs::path& DB::Manager::GetDestinationPath() const
{
    return mDestinationPath;
}

void DB::Manager::SetSourcePath(const fs::path& path)
{
    mSourcePath = path;
}

void DB::Manager::SetDestinationPath(const fs::path& path)
{
    mDestinationPath = path;
}

void DB::Manager::Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders)
{

}
