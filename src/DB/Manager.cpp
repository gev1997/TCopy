#include <ranges>

#include "Manager.h"

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

const DB::FileType& DB::Manager::GetFiles() const
{
    return mFiles;
}

const DB::ExtensionType& DB::Manager::GetExtensions() const
{
    return mExtensions;
}

void DB::Manager::Load(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders)
{
    mSourcePath = sourcePath;
    mDestinationPath = destinationPath;
    mSubFolders = subFolders;
    mFiles.clear();
    mExtensions.clear();

    if (mSubFolders)
        _Load<fs::recursive_directory_iterator>();
    else
        _Load<fs::directory_iterator>();
}

template <typename Iter>
void DB::Manager::_Load()
{
    auto filtered_directory = Iter(mSourcePath)
                              | std::ranges::views::filter([](const auto& entry) { return entry.is_regular_file(); })
                              | std::ranges::views::filter([](const auto& entry) { return !fs::path{entry}.extension().empty(); });

    for (const auto& entry : filtered_directory)
    {
        const DB::File file(entry);
        mFiles.insert(file);
        mExtensions.insert(file.GetExtension());
    }
}
