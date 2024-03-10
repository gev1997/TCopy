#pragma once

#include <wx/msw/registry.h>

class FileSyncApp;

class FileSyncRegistery
{
public:
    enum class Key
    {
        SourceKey,
        DestinationKey
    };

    FileSyncRegistery();
    ~FileSyncRegistery() = default;

    wxString QueryRegisteryValue(Key key);
    void WriteRegisteryValue();

private:
    FileSyncApp& mApp;
    wxRegKey mRegKey;
    std::map<Key, wxString> mKeyMap;
};
