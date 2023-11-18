#include "TCopyDB.h"

TCopyDB::TCopyDB()
{}

const fs::path& TCopyDB::GetSourcePath() const
{
    return mSourcePath;
}

const fs::path& TCopyDB::GetDestinationPath() const
{
    return mDestinationPath;
}

void TCopyDB::SetSourcePath(const fs::path& path)
{
    mSourcePath = path;
}

void TCopyDB::SetDestinationPath(const fs::path& path)
{
    mDestinationPath = path;
}

void TCopyDB::Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders)
{

}
