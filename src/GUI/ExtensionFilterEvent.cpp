#include "ExtensionFilterEvent.h"

wxDEFINE_EVENT(wxEVT_EXTENSION_FILTER, GUI::ExtensionFilterEvent);

GUI::ExtensionFilterEvent::ExtensionFilterEvent(int id, wxEventType eventType)
    : wxEvent{id, eventType}
{}
 
GUI::ExtensionFilterEvent::ExtensionFilterEvent(const ExtensionFilterEvent& event)
    : wxEvent{event}
    , mExtension{event.mExtension}
    , mFilter{event.mFilter}
{}

wxEvent* GUI::ExtensionFilterEvent::Clone() const
{
    return new ExtensionFilterEvent(*this);
}

void GUI::ExtensionFilterEvent::SetExtension(const wxString& extension)
{
    mExtension = extension;
}

void GUI::ExtensionFilterEvent::SetFilter(const DB::FilterType& filter)
{
    mFilter = filter;
}

wxString GUI::ExtensionFilterEvent::GetExtension() const
{
    return mExtension;
}

DB::FilterType GUI::ExtensionFilterEvent::GetFilter() const
{
    return mFilter;
}
