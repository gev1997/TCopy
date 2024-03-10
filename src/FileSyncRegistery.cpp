#include "FileSyncRegistery.h"
#include "FileSyncApp.h"

FileSyncRegistery::FileSyncRegistery()
    : mApp{dynamic_cast<FileSyncApp&>(*wxApp::GetInstance())}
    , mRegKey{wxRegKey::HKCU, "Software\\FileSync"}
    , mKeyMap{{Key::SourceKey, "SourcePath"},
              {Key::DestinationKey, "DestinationPath"}}
{}

wxString FileSyncRegistery::QueryRegisteryValue(FileSyncRegistery::Key key)
{
    if (!mRegKey.Exists())
        return {};

    wxString registeryName(mKeyMap.at(key));

    if (!mRegKey.HasValue(registeryName))
        return {};

    wxString registeryValue;
    mRegKey.QueryValue(registeryName, registeryValue);

    return registeryValue;
}

void FileSyncRegistery::WriteRegisteryValue()
{
    if (!mRegKey.Create())
        return;

    mRegKey.SetValue(mKeyMap.at(Key::SourceKey), mApp.GetDB().GetSourcePath().string());
    mRegKey.SetValue(mKeyMap.at(Key::DestinationKey), mApp.GetDB().GetDestinationPath().string());
}
