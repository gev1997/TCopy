#include <wx/filename.h>

#include "File.h"

DB::File::File(const fs::path& path)
    : mPath{path}
    , mDateTime{wxFileName(mPath.string()).GetModificationTime()}
{}

DB::File::File(const File& file)
    : mPath{file.mPath}
    , mDateTime{wxFileName(mPath.string()).GetModificationTime()}
{}

std::string DB::File::GetFileName() const
{
    return mPath.filename().string();
}

std::string DB::File::GetExtension() const
{
    return mPath.extension().string();
}

bool DB::File::operator<(const File& rhs) const
{
    return mDateTime.IsLaterThan(rhs.mDateTime);
}

bool DB::File::operator>(const File& rhs) const
{
    return mDateTime.IsEarlierThan(rhs.mDateTime);
}

bool DB::File::operator==(const File& rhs) const
{
    return mDateTime.IsSameDate(rhs.mDateTime) && mDateTime.IsSameTime(rhs.mDateTime);
}
