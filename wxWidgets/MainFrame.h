#pragma once
#include<wx/frame.h>

class MainFrame : public wxFrame
{
	public:
		MainFrame(const wxString& title);
		MainFrame();
	private:
		void OnButtonClicked(wxCommandEvent& evt);
		void OnSliderValueChanges(wxCommandEvent& evt);
		void OnTextChanged(wxCommandEvent& evt);
		wxDECLARE_EVENT_TABLE();

		
	

};

