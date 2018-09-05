/***************************************************************
 * Name:      Arudino_LED_Ring_ConfiguratorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2018-09-03
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#include "Arudino_LED_Ring_ConfiguratorMain.h"
#include <wx/msgdlg.h>
#include <wx/colour.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include"SerialPort.h"

using namespace std;

int Inversion(int number);

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
string port = "";
string simulation_data = "";
SerialPort *arduino;

//(*InternalHeaders(Arudino_LED_Ring_ConfiguratorFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Arudino_LED_Ring_ConfiguratorFrame)
const long Arudino_LED_Ring_ConfiguratorFrame::ID_STATICTEXT1 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_TEXTCTRL1 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON2 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON1 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON3 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_STATICTEXT2 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_SLIDER1 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_STATICTEXT3 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_SLIDER2 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_CHECKBOX4 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_CHECKBOX1 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_CHECKBOX2 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_CHECKBOX3 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON4 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON5 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON6 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_RADIOBUTTON7 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_BUTTON1 = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::idMenuQuit = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::idMenuAbout = wxNewId();
const long Arudino_LED_Ring_ConfiguratorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Arudino_LED_Ring_ConfiguratorFrame,wxFrame)
    //(*EventTable(Arudino_LED_Ring_ConfiguratorFrame)
    //*)
END_EVENT_TABLE()

Arudino_LED_Ring_ConfiguratorFrame::Arudino_LED_Ring_ConfiguratorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Arudino_LED_Ring_ConfiguratorFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, wxEmptyString);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Settings "));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Port name :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    TC_PortName = new wxTextCtrl(this, ID_TEXTCTRL1, _("COM3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TC_PortName, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer2->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, this, _("Custom simulations"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    RB_ColorWipe = new wxRadioButton(this, ID_RADIOBUTTON2, _("Color wipe"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    BoxSizer3->Add(RB_ColorWipe, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer3->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    RB_Rainbow = new wxRadioButton(this, ID_RADIOBUTTON1, _("Rainbow"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    BoxSizer3->Add(RB_Rainbow, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer3->Add(-1,-1,0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    RB_Wheel = new wxRadioButton(this, ID_RADIOBUTTON3, _("Wheel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    BoxSizer3->Add(RB_Wheel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer3->Add(BoxSizer3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Brightness  "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer4->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    Slider1 = new wxSlider(this, ID_SLIDER1, 50, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER1"));
    BoxSizer4->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer3->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Speed :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    Slider2 = new wxSlider(this, ID_SLIDER2, 50, 1, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER2"));
    BoxSizer5->Add(Slider2, 1, wxALL|wxALIGN_TOP, 2);
    StaticBoxSizer3->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    CH_CustomColour = new wxCheckBox(this, ID_CHECKBOX4, _("Select custom colour"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    CH_CustomColour->SetValue(false);
    BoxSizer6->Add(CH_CustomColour, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CB_Red = new wxCheckBox(this, ID_CHECKBOX1, _("Red"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CB_Red->SetValue(false);
    BoxSizer6->Add(CB_Red, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CB_Blue = new wxCheckBox(this, ID_CHECKBOX2, _("Blue"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CB_Blue->SetValue(false);
    BoxSizer6->Add(CB_Blue, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    CB_Green = new wxCheckBox(this, ID_CHECKBOX3, _("Green"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    CB_Green->SetValue(false);
    BoxSizer6->Add(CB_Green, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer3->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Full simulations"));
    RB_Simulation1 = new wxRadioButton(this, ID_RADIOBUTTON4, _("Simulation 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    StaticBoxSizer4->Add(RB_Simulation1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    RB_Simulation2 = new wxRadioButton(this, ID_RADIOBUTTON5, _("Simulation 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    StaticBoxSizer4->Add(RB_Simulation2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    RB_Simulation3 = new wxRadioButton(this, ID_RADIOBUTTON6, _("Simulation 3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    StaticBoxSizer4->Add(RB_Simulation3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    RB_Simulation4 = new wxRadioButton(this, ID_RADIOBUTTON7, _("Simulation 4"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON7"));
    StaticBoxSizer4->Add(RB_Simulation4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    StaticBoxSizer1->Add(StaticBoxSizer4, 0, wxALL|wxEXPAND, 2);
    Button1 = new wxButton(this, ID_BUTTON1, _("START"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnRB_ColorWipeSelect);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnRB_RainbowSelect1);
    Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnRB_WheelSelect);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnCH_CustomColourClick);
    Connect(ID_RADIOBUTTON4,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnRB_Simulation1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnButton1Click1);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Arudino_LED_Ring_ConfiguratorFrame::OnAbout);
    //*)


    RB_Wheel->SetValue(true);
    CH_CustomColour->SetValue(true);
    CB_Red->SetValue(true);
    CB_Blue->SetValue(true);

}

Arudino_LED_Ring_ConfiguratorFrame::~Arudino_LED_Ring_ConfiguratorFrame()
{
    //(*Destroy(Arudino_LED_Ring_ConfiguratorFrame)
    //*)
}

void Arudino_LED_Ring_ConfiguratorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Arudino_LED_Ring_ConfiguratorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Arudino_LED_Ring_ConfiguratorFrame::OnButton1Click(wxCommandEvent& event)
{

}

void Arudino_LED_Ring_ConfiguratorFrame::OnButton2Click(wxCommandEvent& event)
{
    port = "\\\\.\\";
    wxString port_name = TC_PortName->GetValue();

    port = port + port_name.mb_str();

    SerialPort arduino1((char *)port.c_str());
    arduino = &arduino1;

	if(arduino->isConnected()){
		wxMessageBox("Connected!", _("SUCCESS"));
	}
	else{
		wxMessageBox("Error in port name!", _("FAILED"));
	}

	port = "";
	port_name = "";
}

void Arudino_LED_Ring_ConfiguratorFrame::OnCH_CustomColourClick(wxCommandEvent& event)
{
    if(CH_CustomColour->GetValue()){

    CB_Red->Enable();
    CB_Blue->Enable();
    CB_Green->Enable();

    }else{

    CB_Red->Disable();
    CB_Blue->Disable();
    CB_Green->Disable();
    CB_Red->SetValue(false);
    CB_Blue->SetValue(false);
    CB_Green->SetValue(false);

    }
}

void Arudino_LED_Ring_ConfiguratorFrame::OnRB_RainbowSelect(wxCommandEvent& event)
{

}



void Arudino_LED_Ring_ConfiguratorFrame::OnRB_RainbowSelect1(wxCommandEvent& event)
{
     if(RB_Rainbow->GetValue()){

        CH_CustomColour->Disable();
        CH_CustomColour->SetValue(false);
        CB_Red->Disable();
        CB_Blue->Disable();
        CB_Green->Disable();
        CB_Red->SetValue(false);
        CB_Blue->SetValue(false);
        CB_Green->SetValue(false);


    }else{

        CH_CustomColour->Enable();
        CB_Red->Enable();
        CB_Blue->Enable();
        CB_Green->Enable();

    }
}

void Arudino_LED_Ring_ConfiguratorFrame::OnRB_WheelSelect(wxCommandEvent& event)
{
    if(RB_Wheel->GetValue()){

        CH_CustomColour->Enable();

    }
}

void Arudino_LED_Ring_ConfiguratorFrame::OnRB_ColorWipeSelect(wxCommandEvent& event)
{
     if(RB_ColorWipe->GetValue()){

        CH_CustomColour->Enable();

    }
}



void Arudino_LED_Ring_ConfiguratorFrame::OnButton1Click1(wxCommandEvent& event)
{
    string data = "";
    port = "\\\\.\\";
    wxString port_name = TC_PortName->GetValue();

    port = port + port_name.mb_str();

    SerialPort arduino((char *)port.c_str());

	if(!arduino.isConnected()){
		wxMessageBox("Error in port name!", _("FAILED"));
	}

	port = "";
	port_name = "";
///-----------------------------------------------------------------------

    if(RB_ColorWipe->GetValue()){

        data = data + "ColorWipe";

    }else if(RB_Rainbow->GetValue()){

        data = data + "Rainbow";

    }else if(RB_Wheel->GetValue()){

        data = data + "Wheel";

    }

    wxString brightness = "";
    brightness << Slider1->GetValue();
    data = data + ":" + brightness;

    wxString speed = "";
    speed << Inversion(Slider2->GetValue());
    data = data + "|" + speed;

    if(RB_ColorWipe->GetValue() && !CH_CustomColour->GetValue()){

        data = data + "!R";

    }else if(RB_Wheel->GetValue() && !CH_CustomColour->GetValue()){

        data = data + "!R";

    }

    if(CB_Red->GetValue() && CB_Blue->GetValue() && CB_Green->GetValue()){
        data = data + "!RBG";
    }else if(CB_Blue->GetValue() && CB_Green->GetValue()){
        data = data + "!BG";
    }else if(CB_Red->GetValue() && CB_Green->GetValue()){
        data = data + "!RG";
    }else if(CB_Red->GetValue() && CB_Blue->GetValue()){
        data = data + "!RB";
    }else if(CB_Green->GetValue()){
        data = data + "!G";
    }else if(CB_Blue->GetValue()){
        data = data + "!B";
    }else if(CB_Red->GetValue()){
        data = data + "!R";
    }

    if(arduino.isConnected()){

		char *charArray = new char[data.size() + 1];

		if(RB_Simulation1->GetValue()){

        simulation_data = "Simulation1";
        copy(simulation_data.begin(), simulation_data.end(), charArray);
		charArray[simulation_data.size()] = '\n';
        arduino.writeSerialPort(charArray, simulation_data.size());
        simulation_data="";

		}else if(RB_Simulation2->GetValue()){

        simulation_data = "Simulation2";
        copy(simulation_data.begin(), simulation_data.end(), charArray);
		charArray[simulation_data.size()] = '\n';
        arduino.writeSerialPort(charArray, simulation_data.size());
        simulation_data="";

        }else if(RB_Simulation3->GetValue()){

        simulation_data = "Simulation3";
        copy(simulation_data.begin(), simulation_data.end(), charArray);
		charArray[simulation_data.size()] = '\n';
        arduino.writeSerialPort(charArray, simulation_data.size());
        simulation_data="";

        }else if(RB_Simulation4->GetValue()){

        simulation_data = "Simulation4";
        copy(simulation_data.begin(), simulation_data.end(), charArray);
		charArray[simulation_data.size()] = '\n';
        arduino.writeSerialPort(charArray, simulation_data.size());
        simulation_data="";

        }else{

		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';
		arduino.writeSerialPort(charArray, data.size());
        }


		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		delete [] charArray;

	}

	data = "";
}

void Arudino_LED_Ring_ConfiguratorFrame::OnRB_Simulation1Select(wxCommandEvent& event)
{
    if(RB_Simulation1->GetValue()){

        simulation_data = "Simulation1";
    }
}

int Inversion(int number){

    int arr[101];
    int j = 100;

    for(int i = 1; i < 101; i++){

        arr[j] = i;
        j--;

    }

    number = arr[number];

    return number;
}
