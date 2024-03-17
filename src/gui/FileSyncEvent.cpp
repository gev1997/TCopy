#include "FileSyncEvent.h"

wxDEFINE_EVENT(wxEVT_EXTENSION_FILTER, gui::ExtensionFilterEvent);

gui::ExtensionFilterEvent::ExtensionFilterEvent(int id, wxEventType eventType)
    : wxEvent{id, eventType}
{}
 
gui::ExtensionFilterEvent::ExtensionFilterEvent(const ExtensionFilterEvent& event)
    : wxEvent{event}
    , mExtension{event.mExtension}
    , mFilter{event.mFilter}
{}

wxEvent* gui::ExtensionFilterEvent::Clone() const
{
    return new ExtensionFilterEvent(*this);
}

void gui::ExtensionFilterEvent::SetExtension(const wxString& extension)
{
    mExtension = extension;
}

void gui::ExtensionFilterEvent::SetFilter(const DB::FilterType& filter)
{
    mFilter = filter;
}

wxString gui::ExtensionFilterEvent::GetExtension() const
{
    return mExtension;
}

DB::FilterType gui::ExtensionFilterEvent::GetFilter() const
{
    return mFilter;
}
