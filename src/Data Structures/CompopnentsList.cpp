#include "Data Structures/CompopnentsList.h"
#include "Electronic Components/Electronics.h"

CompopnentsList::CompopnentsList()
{
    for(int i = 0; i < 50; i++)
        componentsList[i] = NULL;
}

int CompopnentsList::getNumberOfComponents(){
    return numberOfComponents;
}

void CompopnentsList::addComponent(int cType){
    if(numberOfComponents == 50)    return;

    numberOfComponents++;

    int i = 0;  while(componentsList[i] != NULL)    i++;

    for(int j = 0; j < 50; j++) if(j != i && componentsList[j] != NULL)  componentsList[j]->setOutterBox(false);

    if(cType == _capacitorCeramic) componentsList[i] = new Capacitor_Ceramic;
    else if(cType == _capacitorElectrolyt) componentsList[i] = new Capacitor_Electrolytic;
    else if(cType == _capacitorTrimmer) componentsList[i] = new Capacitor_Trimmer;
    else if(cType == _capacitorVariable) componentsList[i] = new Capacitor_Variable;
    else if(cType == _diodeAvalance) componentsList[i] = new Diode_Avalance;
    else if(cType == _diodeConstantCurrent) componentsList[i] = new Diode_Constant_Current;
    else if(cType == _diodeGunn) componentsList[i] = new Diode_Gunn;
    else if(cType == _diodeJunction) componentsList[i] = new Diode_Junction_PN;
    else if(cType == _diodeLaser) componentsList[i] = new Diode_Laser;
    else if(cType == _diodeLightEmitting) componentsList[i] = new Diode_Light_Emitting;
    else if(cType == _diodePhoto) componentsList[i] = new Diode_Photo;
    else if(cType == _diodePin) componentsList[i] = new Diode_PIN;
    else if(cType == _diodeSchottky) componentsList[i] = new Diode_Schottky;
    else if(cType == _diodeShockley) componentsList[i] = new Diode_Shockley;
    else if(cType == _diodeVoltage) componentsList[i] = new Diode_Transient_Voltage_Suppression;
    else if(cType == _diodeTunnel) componentsList[i] = new Diode_Tunnel;
    else if(cType == _diodeVaractor) componentsList[i] = new Diode_Varactor;
    else if(cType == _diodeZener) componentsList[i] = new Diode_Zener;
    else if(cType == _andGate) componentsList[i] = new AndGate;
    else if(cType == _nandGate) componentsList[i] = new NandGate;
    else if(cType == _norGate) componentsList[i] = new NorGate;
    else if(cType == _notGate) componentsList[i] = new NotGate;
    else if(cType == _orGate) componentsList[i] = new OrGate;
    else if(cType == _xorGate) componentsList[i] = new XorGate;
    else if(cType == _ammeter) componentsList[i] = new Ammeter;
    else if(cType == _voltmeter) componentsList[i] = new Voltmeter;
    else if(cType == _potentiometer) componentsList[i] = new Potentiometer_Mobile_Contact;
    else if(cType == _resistor) componentsList[i] = new Resistor;
    else if(cType == _resistorMobile) componentsList[i] = new Resistor_Mobile_Contact;
    else if(cType == _resistorMobileStop) componentsList[i] = new Resistor_Mobile_Contact_Stop_Position;
    else if(cType == _resistorVariableResistance) componentsList[i] = new Resistor_Variable_Resistance;
    else if(cType == _battery) componentsList[i] = new Battery;
    else if(cType == _sourceAC) componentsList[i] = new Source_Voltage_AC;
    else if(cType == _sourceDC) componentsList[i] = new Source_Voltage_DC;
    else if(cType == _switchClosed) componentsList[i] = new Switch_Closed;
    else if(cType == _switchDPST) componentsList[i] = new Switch_DPST;
    else if(cType == _switchOpen) componentsList[i] = new Switch_Open;
    else if(cType == _switchSPDT) componentsList[i] = new Switch_SPDT;
    else if(cType == _switchTelegraph) componentsList[i] = new Switch_Telegraph;
    else if(cType == _switchThermal) componentsList[i] = new Switch_Thermal_Magnetic_Breaker;
    else if(cType == _transistorBipolarNPN) componentsList[i] = new Transistor_Bipolar_NPN;
    else if(cType == _transistorBipolarPNP) componentsList[i] = new Transistor_Bipolar_PNP;
    else if(cType == _transistorDualN) componentsList[i] = new Transistor_Dual_Gate_MOSFET_Nchannel;
    else if(cType == _transistorDualP) componentsList[i] = new Transistor_Dual_Gate_MOSFET_Pchannel;
    else if(cType == _transistorFETN) componentsList[i] = new Transistor_FET_Nchannel;
    else if(cType == _transistorFETP) componentsList[i] = new Transistor_FET_Pchannel;
    else if(cType == _transistorInductiveN) componentsList[i] = new Transistor_Inductive_Channel_MOSFET_Nchannel;
    else if(cType == _transistorInductiveP) componentsList[i] = new Transistor_Inductive_Channel_MOSFET_Pchannel;
    else if(cType == _transistorMOSFETN) componentsList[i] = new Transistor_MOSFET_Nchannel;
    else if(cType == _transistorMOSFETP) componentsList[i] = new Transistor_MOSFET_Pchannel;
    else if(cType == _transistorSingleN) componentsList[i] = new Transistor_Single_Connection_Nchannel;
    else if(cType == _transistorSingleP) componentsList[i] = new Transistor_Single_Connection_Pchannel;
    else if(cType == _buzzer) componentsList[i] = new Buzzer;
    else if(cType == _ground) componentsList[i] = new Ground;
    else if(cType == _inductor) componentsList[i] = new Inductor;
    else if(cType == _lamp) componentsList[i] = new Lamp;
    else if(cType == _microphone) componentsList[i] = new Microphone;
    else if(cType == _motor) componentsList[i] = new Motor;
    else if(cType == _speaker) componentsList[i] = new Speaker;
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
