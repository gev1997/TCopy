#include "File.h"

DB::File::File(const fs::path& path)
    : mPath{path}
{}

DB::File::File(const File& file)
    : mPath{file.mPath}
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
    return true;
}

bool DB::File::operator>(const File& rhs) const
{
    return true;
}

bool DB::File::operator==(const File& rhs) const
{
    return true;
}
