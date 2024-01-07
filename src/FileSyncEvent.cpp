#include "FileSyncEvent.h"

wxDEFINE_EVENT(wxEVT_EXTENSION_FILTER, wxExtensionFilterEvent);

wxExtensionFilterEvent::wxExtensionFilterEvent(int id, wxEventType eventType)
    : wxEvent(id, eventType)
{}
 
wxExtensionFilterEvent::wxExtensionFilterEvent(const wxExtensionFilterEvent& event)
    : wxEvent(event)
    , mExtension{event.mExtension}
    , mFilter{event.mFilter}
{}

wxEvent* wxExtensionFilterEvent::Clone() const
{
    return new wxExtensionFilterEvent(*this);
}

void wxExtensionFilterEvent::SetExtension(const wxString& extension)
{
    mExtension = extension;
}

void wxExtensionFilterEvent::SetFilter(const DB::FilterType& filter)
{
    mFilter = filter;
}

wxString wxExtensionFilterEvent::GetExtension() const
{
    return mExtension;
}

DB::FilterType wxExtensionFilterEvent::GetFilter() const
{
    return mFilter;
}
