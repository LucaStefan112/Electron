#ifndef ELECTRONICS_H
#define ELECTRONICS_H

//Header for including all electronic components headers:
#include "Diode.h"
#include "Capacitor.h"
#include "Switch.h"
#include "Battery.h"
#include "Ampermeter.h"
#include "Voltmeter.h"
#include "Ground.h"
#include "Rezistor.h"
#include "Inductor.h"
#include "Buzzer.h"
#include "Lamp.h"
#include "Speaker.h"
#include "Microphone.h"
#include "Motor.h"

//Logic Gates:
#include "Electronic Components/Logic Gates/NotGate.h"
#include "Electronic Components/Logic Gates/AndGate.h"
#include "Electronic Components/Logic Gates/NandGate.h"
#include "Electronic Components/Logic Gates/OrGate.h"
#include "Electronic Components/Logic Gates/NorGate.h"
#include "Electronic Components/Logic Gates/XorGate.h"

//Transistors:
#include "Electronic Components/Transistors/Transistor_Bipolar_NPN.h"
#include "Electronic Components/Transistors/Transistor_Bipolar_PNP.h"
#include "Electronic Components/Transistors/Transistor_FET_Nchannel.h"
#include "Electronic Components/Transistors/Transistor_FET_Pchannel.h"
#include "Electronic Components/Transistors/Transistor_MOSFET_Nchannel.h"
#include "Electronic Components/Transistors/Transistor_MOSFET_Pchannel.h"
#include "Electronic Components/Transistors/Transistor_Dual_Gate_MOSFET_Nchannel.h"
#include "Electronic Components/Transistors/Transistor_Dual_Gate_MOSFET_Pchannel.h"
#include "Electronic Components/Transistors/Transistor_Inductive_Channel_MOSFET_Nchannel.h"
#include "Electronic Components/Transistors/Transistor_Inductive_Channel_MOSFET_Pchannel.h"
#include "Electronic Components/Transistors/Transistor_Single_Connection_Nchannel.h"
#include "Electronic Components/Transistors/Transistor_Single_Connection_Pchannel.h"

//Sources:
#include "Electronic Components/Sources/Source_Voltage_DC.h"
#include "Electronic Components/Sources/Source_Voltage_AC.h"

#endif // ELECTRONICS_H
