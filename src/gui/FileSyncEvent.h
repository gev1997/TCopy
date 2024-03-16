#pragma once

#include <wx/event.h>
#include <wx/string.h>

class wxExtensionFilterEvent;
wxDECLARE_EVENT(wxEVT_EXTENSION_FILTER, wxExtensionFilterEvent);

class wxExtensionFilterEvent : public wxEvent
{
public:
    wxExtensionFilterEvent(int id = 0, wxEventType eventType = wxEVT_EXTENSION_FILTER);
	wxExtensionFilterEvent(const wxExtensionFilterEvent& event);

	wxEvent* Clone() const override;
	void SetExtension(const wxString& extension);
	void SetFilter(const DB::FilterType& filter);
	wxString GetExtension() const;
	DB::FilterType GetFilter() const;

private:
	wxString mExtension;
	DB::FilterType mFilter;
};
