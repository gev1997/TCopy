#pragma once

#include <wx/event.h>
#include <wx/string.h>

namespace gui { class ExtensionFilterEvent; };

wxDECLARE_EVENT(wxEVT_EXTENSION_FILTER, gui::ExtensionFilterEvent);

class gui::ExtensionFilterEvent : public wxEvent
{
public:
    ExtensionFilterEvent(int id = 0, wxEventType eventType = wxEVT_EXTENSION_FILTER);
	ExtensionFilterEvent(const ExtensionFilterEvent& event);

	wxEvent* Clone() const override;
	void SetExtension(const wxString& extension);
	void SetFilter(const DB::FilterType& filter);
	wxString GetExtension() const;
	DB::FilterType GetFilter() const;

private:
	wxString mExtension;
	DB::FilterType mFilter;
};
