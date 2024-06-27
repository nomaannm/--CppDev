#include"MainFrame.h"
#include<wx/wx.h>
#include<wx/spinctrl.h>

enum IDs {
	BUTTON_ID = 2, TEXT_ID, SLIDER_ID
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClicked)
	EVT_SLIDER(SLIDER_ID, MainFrame::OnSliderValueChanges)
	EVT_TEXT(TEXT_ID, MainFrame::OnTextChanged)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);
	wxButton* btn = new wxButton(panel, BUTTON_ID, "Button", wxPoint(300, 275), wxSize(200, 50));
	wxTextCtrl* txtCtrl = new wxTextCtrl(panel, TEXT_ID, " ", wxPoint(400, 200), wxSize(150, -1));
	wxSlider* slider = new wxSlider(panel, SLIDER_ID, 0, 0, 100, wxPoint(100, 400), wxSize(200, 200));



	CreateStatusBar();

} 

void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	wxLogStatus("Button clicked");

}

void MainFrame::OnSliderValueChanges(wxCommandEvent& evt) {
	wxString str = wxString::Format("Slider's value : %d", evt.GetInt());
	wxLogStatus(str);
}

void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text : %s", evt.GetString());
	wxLogStatus(str);
}
