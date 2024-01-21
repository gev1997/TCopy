#include <Shlobj.h>

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

void DB::Manager::Filter(const std::string& extension, FilterType filter)
{
    const auto isSameExtension = [&](const auto& file) { return file.GetExtension() == extension; };

    switch (filter)
    {
        case FilterType::Insert:
            for (const auto& file : mFiles | std::views::filter(isSameExtension))
                mVisibleFiles.insert(file);
            break;

        case FilterType::Remove:
            std::erase_if(mVisibleFiles, isSameExtension);
            break;

        case FilterType::Reset:
            mVisibleFiles = mFiles;
            break;

        case FilterType::Clear:
            mVisibleFiles.clear();
            break;
    }
}

void DB::Manager::SetData(const fs::path& sourcePath, const fs::path& destinationPath, bool subFolders)
{
    mSourcePath = sourcePath;
    mDestinationPath = destinationPath;
    mSubFolders = subFolders;
}

long DB::Manager::CopyFiles(const std::vector<int>& checkedItems)
{
    assert(checkedItems.size());

    IFileOperation* fileOperation = nullptr;

    long result = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    if (SUCCEEDED(result))
    {
        result = CoCreateInstance(CLSID_FileOperation, NULL, CLSCTX_ALL, IID_PPV_ARGS(&fileOperation));

        if (SUCCEEDED(result))
        {
            const std::vector<File> visibleFiles(mVisibleFiles.begin(), mVisibleFiles.end());

            for (auto itemIndex : checkedItems)
            {
                const fs::path sourceFilePath = visibleFiles[itemIndex].GetPath();
                const fs::path relativePath = sourceFilePath.string().erase(0, mSourcePath.string().size());
                fs::path destinationFilePath = mDestinationPath;
                destinationFilePath += relativePath.parent_path();

                if (!fs::exists(destinationFilePath))
                    fs::create_directories(destinationFilePath);

                IShellItem* sourceShellItem = nullptr;
                IShellItem* destinationShellItem = nullptr;

                result = SHCreateItemFromParsingName(sourceFilePath.wstring().c_str(), NULL, IID_PPV_ARGS(&sourceShellItem));

                if (SUCCEEDED(result))
                   result = SHCreateItemFromParsingName(destinationFilePath.wstring().c_str(), NULL, IID_PPV_ARGS(&destinationShellItem));

                if (SUCCEEDED(result))
                    result = fileOperation->CopyItem(sourceShellItem, destinationShellItem, nullptr, nullptr);

                if (sourceShellItem)
                    sourceShellItem->Release();

                if (destinationShellItem)
                    destinationShellItem->Release();
            }

            if (SUCCEEDED(result))
                result = fileOperation->PerformOperations();

            fileOperation->Release();
        }

        CoUninitialize();
    }

    return result;
}

void DB::Manager::Load()
{
    assert(!mSourcePath.empty());
    assert(!mDestinationPath.empty());

    mFiles.clear();
    mVisibleFiles.clear();
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
