#include "CompopnentsList.h"
#include "Electronics.h"

CompopnentsList::CompopnentsList()
{
    for(int i = 0; i < 50; i++)
        componentsList[i] = NULL;
}

int CompopnentsList::getNumberOfComponents(){
    return numberOfComponents;
}

void CompopnentsList::addComponent(std::string typeOfComponent){
    if(numberOfComponents == 50)    return;

    numberOfComponents++;

    int i = 0;  while(componentsList[i] != NULL)    i++;

    for(int j = 0; j < 50; j++) if(j != i && componentsList[j] != NULL)  componentsList[j]->setOutterBox(false);

    if(typeOfComponent == std::string("Ceramic Capacitor")) componentsList[i] = new Capacitor_Ceramic;
    else if(typeOfComponent == std::string("Electrolytic Capacitor")) componentsList[i] = new Capacitor_Electrolytic;
    else if(typeOfComponent == std::string("Trimmer Capacitor")) componentsList[i] = new Capacitor_Trimmer;
    else if(typeOfComponent == std::string("Variable Capacitor")) componentsList[i] = new Capacitor_Variable;
    else if(typeOfComponent == std::string("Avalance Diode")) componentsList[i] = new Diode_Avalance;
    else if(typeOfComponent == std::string("Constant Current Diode")) componentsList[i] = new Diode_Constant_Current;
    else if(typeOfComponent == std::string("Gunn Diode")) componentsList[i] = new Diode_Gunn;
    else if(typeOfComponent == std::string("PN Junction Diode")) componentsList[i] = new Diode_Junction_PN;
    else if(typeOfComponent == std::string("Laser Diode")) componentsList[i] = new Diode_Laser;
    else if(typeOfComponent == std::string("Light Emitting Diode")) componentsList[i] = new Diode_Light_Emitting;
    else if(typeOfComponent == std::string("Photo Diode")) componentsList[i] = new Diode_Photo;
    else if(typeOfComponent == std::string("PIN Diode")) componentsList[i] = new Diode_PIN;
    else if(typeOfComponent == std::string("Schottky Diode")) componentsList[i] = new Diode_Schottky;
    else if(typeOfComponent == std::string("Shockley Diode")) componentsList[i] = new Diode_Shockley;
    else if(typeOfComponent == std::string("Transient Voltage Suppression Diode")) componentsList[i] = new Diode_Transient_Voltage_Suppression;
    else if(typeOfComponent == std::string("Tunnel Diode")) componentsList[i] = new Diode_Tunnel;
    else if(typeOfComponent == std::string("Varactor Diode")) componentsList[i] = new Diode_Varactor;
    else if(typeOfComponent == std::string("Zener Diode")) componentsList[i] = new Diode_Zener;
    else if(typeOfComponent == std::string("And Gate")) componentsList[i] = new AndGate;
    else if(typeOfComponent == std::string("Nand Gate")) componentsList[i] = new NandGate;
    else if(typeOfComponent == std::string("Nor Gate")) componentsList[i] = new NorGate;
    else if(typeOfComponent == std::string("Not Gate")) componentsList[i] = new NotGate;
    else if(typeOfComponent == std::string("Or Gate")) componentsList[i] = new OrGate;
    else if(typeOfComponent == std::string("Xor Gate")) componentsList[i] = new XorGate;
    else if(typeOfComponent == std::string("Ammeter")) componentsList[i] = new Ammeter;
    else if(typeOfComponent == std::string("Voltmeter")) componentsList[i] = new Voltmeter;
    else if(typeOfComponent == std::string("Mobile Contact Potentiometer")) componentsList[i] = new Potentiometer_Mobile_Contact;
    else if(typeOfComponent == std::string("Resistor")) componentsList[i] = new Resistor;
    else if(typeOfComponent == std::string("Mobile Contact Resistor")) componentsList[i] = new Resistor_Mobile_Contact;
    else if(typeOfComponent == std::string("Mobile Contact and Stop Position Resistor")) componentsList[i] = new Resistor_Mobile_Contact_Stop_Position;
    else if(typeOfComponent == std::string("Variable Resistance Resistor")) componentsList[i] = new Resistor_Variable_Resistance;
    else if(typeOfComponent == std::string("Battery")) componentsList[i] = new Battery;
    else if(typeOfComponent == std::string("AC Voltage Source")) componentsList[i] = new Source_Voltage_AC;
    else if(typeOfComponent == std::string("DC Voltage Source")) componentsList[i] = new Source_Voltage_DC;
    else if(typeOfComponent == std::string("Closed Switch")) componentsList[i] = new Switch_Closed;
    else if(typeOfComponent == std::string("DPST Switch")) componentsList[i] = new Switch_DPST;
    else if(typeOfComponent == std::string("Open Switch")) componentsList[i] = new Switch_Open;
    else if(typeOfComponent == std::string("SPDT Switch")) componentsList[i] = new Switch_SPDT;
    else if(typeOfComponent == std::string("Telegraph Switch")) componentsList[i] = new Switch_Telegraph;
    else if(typeOfComponent == std::string("Thermal Magnetic Breaker Switch")) componentsList[i] = new Switch_Thermal_Magnetic_Breaker;
    else if(typeOfComponent == std::string("Bipolar NPN Transistor")) componentsList[i] = new Transistor_Bipolar_NPN;
    else if(typeOfComponent == std::string("Bipolar PNP Transistor")) componentsList[i] = new Transistor_Bipolar_PNP;
    else if(typeOfComponent == std::string("Dual Gate MOSFET N-channel Transistor")) componentsList[i] = new Transistor_Dual_Gate_MOSFET_Nchannel;
    else if(typeOfComponent == std::string("Dual Gate MOSFET P-channel Transistor")) componentsList[i] = new Transistor_Dual_Gate_MOSFET_Pchannel;
    else if(typeOfComponent == std::string("FET N-channel Transistor")) componentsList[i] = new Transistor_FET_Nchannel;
    else if(typeOfComponent == std::string("FET P-channel Transistor")) componentsList[i] = new Transistor_FET_Pchannel;
    else if(typeOfComponent == std::string("MOSFET Inductive Channel N-channel Transistor")) componentsList[i] = new Transistor_Inductive_Channel_MOSFET_Nchannel;
    else if(typeOfComponent == std::string("MOSFET Inductive Channel P-channel Transistor")) componentsList[i] = new Transistor_Inductive_Channel_MOSFET_Pchannel;
    else if(typeOfComponent == std::string("MOSFET N-channel Transistor")) componentsList[i] = new Transistor_MOSFET_Nchannel;
    else if(typeOfComponent == std::string("MOSFET P-channel Transistor")) componentsList[i] = new Transistor_MOSFET_Pchannel;
    else if(typeOfComponent == std::string("Single Connection N-channel Transistor")) componentsList[i] = new Transistor_Single_Connection_Nchannel;
    else if(typeOfComponent == std::string("Single Connection P-channel Transistor")) componentsList[i] = new Transistor_Single_Connection_Pchannel;
    else if(typeOfComponent == std::string("Buzzer")) componentsList[i] = new Buzzer;
    else if(typeOfComponent == std::string("Ground")) componentsList[i] = new Ground;
    else if(typeOfComponent == std::string("Inductor")) componentsList[i] = new Inductor;
    else if(typeOfComponent == std::string("Lamp")) componentsList[i] = new Lamp;
    else if(typeOfComponent == std::string("Microphone")) componentsList[i] = new Microphone;
    else if(typeOfComponent == std::string("Motor")) componentsList[i] = new Motor;
    else if(typeOfComponent == std::string("Speaker")) componentsList[i] = new Speaker;
    else return;

    componentsList[i]->setOutterBox(true);
}

void CompopnentsList::removeComponent(std::string thisComponentCode){
    int i = 0;  while(componentsList[i]->componentCode != thisComponentCode && i < 50)    i++;

    if(i == 50) return;

    delete componentsList[i];

    componentsList[i] = NULL;
}

ElectronicComponent* CompopnentsList::getSelectedComponent(){
    for(int i = 0; i < 50; i++)
        if(componentsList[i]->isSelected())
            return componentsList[i];

    return NULL;
}
