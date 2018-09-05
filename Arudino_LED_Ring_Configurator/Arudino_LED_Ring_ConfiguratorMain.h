/***************************************************************
 * Name:      Arudino_LED_Ring_ConfiguratorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2018-09-03
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef ARUDINO_LED_RING_CONFIGURATORMAIN_H
#define ARUDINO_LED_RING_CONFIGURATORMAIN_H

//(*Headers(Arudino_LED_Ring_ConfiguratorFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class Arudino_LED_Ring_ConfiguratorFrame: public wxFrame
{
    public:

        Arudino_LED_Ring_ConfiguratorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Arudino_LED_Ring_ConfiguratorFrame();

    private:

        //(*Handlers(Arudino_LED_Ring_ConfiguratorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnCH_CustomColourClick(wxCommandEvent& event);
        void OnRB_RainbowSelect(wxCommandEvent& event);
        void OnCB_RainbowClick(wxCommandEvent& event);
        void OnRB_RainbowSelect1(wxCommandEvent& event);
        void OnRB_WheelSelect(wxCommandEvent& event);
        void OnRB_ColorWipeSelect(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnRB_Simulation1Select(wxCommandEvent& event);
        //*)

        //(*Identifiers(Arudino_LED_Ring_ConfiguratorFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON3;
        static const long ID_STATICTEXT2;
        static const long ID_SLIDER1;
        static const long ID_STATICTEXT3;
        static const long ID_SLIDER2;
        static const long ID_CHECKBOX4;
        static const long ID_CHECKBOX1;
        static const long ID_CHECKBOX2;
        static const long ID_CHECKBOX3;
        static const long ID_RADIOBUTTON4;
        static const long ID_RADIOBUTTON5;
        static const long ID_RADIOBUTTON6;
        static const long ID_RADIOBUTTON7;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Arudino_LED_Ring_ConfiguratorFrame)
        wxButton* Button1;
        wxCheckBox* CB_Blue;
        wxCheckBox* CB_Green;
        wxCheckBox* CB_Red;
        wxCheckBox* CH_CustomColour;
        wxRadioButton* RB_ColorWipe;
        wxRadioButton* RB_Rainbow;
        wxRadioButton* RB_Simulation1;
        wxRadioButton* RB_Simulation2;
        wxRadioButton* RB_Simulation3;
        wxRadioButton* RB_Simulation4;
        wxRadioButton* RB_Wheel;
        wxSlider* Slider1;
        wxSlider* Slider2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TC_PortName;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ARUDINO_LED_RING_CONFIGURATORMAIN_H
