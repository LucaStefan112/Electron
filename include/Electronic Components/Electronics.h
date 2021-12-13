#ifndef ELECTRONICS_H
#define ELECTRONICS_H

//Header for including all electronic components headers:
#include "Switch.h"
#include "Ampermeter.h"
#include "Voltmeter.h"
#include "Ground.h"
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
#include "Electronic Components/Sources/Battery.h"

//Diodes:
#include "Electronic Components/Diodes/Diode_Junction_PN.h"
#include "Electronic Components/Diodes/Diode_Zener.h"
#include "Electronic Components/Diodes/Diode_Light_Emitting.h"
#include "Electronic Components/Diodes/Diode_Constant_Current.h"
#include "Electronic Components/Diodes/Diode_Schottky.h"
#include "Electronic Components/Diodes/Diode_Tunnel.h"
#include "Electronic Components/Diodes/Diode_Varactor.h"
#include "Electronic Components/Diodes/Diode_PIN.h"
#include "Electronic Components/Diodes/Diode_Photo.h"
#include "Electronic Components/Diodes/Diode_Laser.h"
#include "Electronic Components/Diodes/Diode_Transient_Voltage_Suppression.h"
#include "Electronic Components/Diodes/Diode_Avalance.h"
#include "Electronic Components/Diodes/Diode_Gunn.h"

//Capacitors:
#include "Electronic Components/Capacitors/Capacitor_Ceramic.h"
#include "Electronic Components/Capacitors/Capacitor_Electrolytic.h"
#include "Electronic Components/Capacitors/Capacitor_Trimmer.h"
#include "Electronic Components/Capacitors/Capacitor_Variable.h"

//Resistors:
#include "Electronic Components/Resistors/Resistor.h"
#include "Electronic Components/Resistors/Resistor_Variable_Resistance.h"

#endif // ELECTRONICS_H
