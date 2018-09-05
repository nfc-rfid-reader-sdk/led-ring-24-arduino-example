/***************************************************************
 * Name:      Arudino_LED_Ring_ConfiguratorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2018-09-03
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#include "Arudino_LED_Ring_ConfiguratorApp.h"

//(*AppHeaders
#include "Arudino_LED_Ring_ConfiguratorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Arudino_LED_Ring_ConfiguratorApp);

bool Arudino_LED_Ring_ConfiguratorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Arudino_LED_Ring_ConfiguratorFrame* Frame = new Arudino_LED_Ring_ConfiguratorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
