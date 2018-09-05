/***************************************************************
 * Name:      Arudino_LED_Ring_ConfiguratorApp.h
 * Purpose:   Defines Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2018-09-03
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef ARUDINO_LED_RING_CONFIGURATORAPP_H
#define ARUDINO_LED_RING_CONFIGURATORAPP_H

#include <wx/app.h>

class Arudino_LED_Ring_ConfiguratorApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // ARUDINO_LED_RING_CONFIGURATORAPP_H
