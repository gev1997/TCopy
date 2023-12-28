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
    return mVisibleFiles;
}

const DB::ExtensionType& DB::Manager::GetExtensions() const
{
    return mExtensions;
}

void DB::Manager::Filter(const std::list<std::string>& extensions)
{
    if (extensions.empty())
        return;

    mVisibleFiles.clear();

    for (const auto& extension : extensions)
    {
        for (const auto& file : mFiles | std::views::filter([&](const auto& file) { return extension == file.GetExtension(); }))
        {
            mVisibleFiles.insert(file);
        }
    }
}

void DB::Manager::SetData(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders)
{
    mSourcePath = sourcePath;
    mDestinationPath = destinationPath;
    mSubFolders = subFolders;
}

void DB::Manager::Load()
{
    assert(!mSourcePath.empty());
    assert(!mDestinationPath.empty());

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

    mVisibleFiles = mFiles;
}
