#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Electronic Components/ElectronicComponent.h"
#include "Data Structures/Snapshot.h"

Snapshot::Snapshot() {
    for(int i = 0; i < 100; i++) {
        current[i] = NULL;
    }
}

void Snapshot::addComponent(int cType) {
    for(int i = 0; i < sizeOfCurrent; i++) {
        current[i]->setOutterBox(false);
    }

    if(cType == _capacitorCeramic) current[sizeOfCurrent] = new Capacitor_Ceramic;
    else if(cType == _capacitorElectrolyt) current[sizeOfCurrent] = new Capacitor_Electrolytic;
    else if(cType == _capacitorTrimmer) current[sizeOfCurrent] = new Capacitor_Trimmer;
    else if(cType == _capacitorVariable) current[sizeOfCurrent] = new Capacitor_Variable;
    else if(cType == _diodeAvalance) current[sizeOfCurrent] = new Diode_Avalance;
    else if(cType == _diodeConstantCurrent) current[sizeOfCurrent] = new Diode_Constant_Current;
    else if(cType == _diodeGunn) current[sizeOfCurrent] = new Diode_Gunn;
    else if(cType == _diodeJunction) current[sizeOfCurrent] = new Diode_Junction_PN;
    else if(cType == _diodeLaser) current[sizeOfCurrent] = new Diode_Laser;
    else if(cType == _diodeLightEmitting) current[sizeOfCurrent] = new Diode_Light_Emitting;
    else if(cType == _diodePhoto) current[sizeOfCurrent] = new Diode_Photo;
    else if(cType == _diodePin) current[sizeOfCurrent] = new Diode_PIN;
    else if(cType == _diodeSchottky) current[sizeOfCurrent] = new Diode_Schottky;
    else if(cType == _diodeShockley) current[sizeOfCurrent] = new Diode_Shockley;
    else if(cType == _diodeVoltage) current[sizeOfCurrent] = new Diode_Transient_Voltage_Suppression;
    else if(cType == _diodeTunnel) current[sizeOfCurrent] = new Diode_Tunnel;
    else if(cType == _diodeVaractor) current[sizeOfCurrent] = new Diode_Varactor;
    else if(cType == _diodeZener) current[sizeOfCurrent] = new Diode_Zener;
    else if(cType == _andGate) current[sizeOfCurrent] = new AndGate;
    else if(cType == _nandGate) current[sizeOfCurrent] = new NandGate;
    else if(cType == _norGate) current[sizeOfCurrent] = new NorGate;
    else if(cType == _notGate) current[sizeOfCurrent] = new NotGate;
    else if(cType == _orGate) current[sizeOfCurrent] = new OrGate;
    else if(cType == _xorGate) current[sizeOfCurrent] = new XorGate;
    else if(cType == _ammeter) current[sizeOfCurrent] = new Ammeter;
    else if(cType == _voltmeter) current[sizeOfCurrent] = new Voltmeter;
    else if(cType == _potentiometer) current[sizeOfCurrent] = new Potentiometer_Mobile_Contact;
    else if(cType == _resistor) current[sizeOfCurrent] = new Resistor;
    else if(cType == _resistorMobile) current[sizeOfCurrent] = new Resistor_Mobile_Contact;
    else if(cType == _resistorMobileStop) current[sizeOfCurrent] = new Resistor_Mobile_Contact_Stop_Position;
    else if(cType == _resistorVariableResistance) current[sizeOfCurrent] = new Resistor_Variable_Resistance;
    else if(cType == _battery) current[sizeOfCurrent] = new Battery;
    else if(cType == _sourceAC) current[sizeOfCurrent] = new Source_Voltage_AC;
    else if(cType == _sourceDC) current[sizeOfCurrent] = new Source_Voltage_DC;
    else if(cType == _switchClosed) current[sizeOfCurrent] = new Switch_Closed;
    else if(cType == _switchDPST) current[sizeOfCurrent] = new Switch_DPST;
    else if(cType == _switchOpen) current[sizeOfCurrent] = new Switch_Open;
    else if(cType == _switchSPDT) current[sizeOfCurrent] = new Switch_SPDT;
    else if(cType == _switchTelegraph) current[sizeOfCurrent] = new Switch_Telegraph;
    else if(cType == _switchThermal) current[sizeOfCurrent] = new Switch_Thermal_Magnetic_Breaker;
    else if(cType == _transistorBipolarNPN) current[sizeOfCurrent] = new Transistor_Bipolar_NPN;
    else if(cType == _transistorBipolarPNP) current[sizeOfCurrent] = new Transistor_Bipolar_PNP;
    else if(cType == _transistorDualN) current[sizeOfCurrent] = new Transistor_Dual_Gate_MOSFET_Nchannel;
    else if(cType == _transistorDualP) current[sizeOfCurrent] = new Transistor_Dual_Gate_MOSFET_Pchannel;
    else if(cType == _transistorFETN) current[sizeOfCurrent] = new Transistor_FET_Nchannel;
    else if(cType == _transistorFETP) current[sizeOfCurrent] = new Transistor_FET_Pchannel;
    else if(cType == _transistorInductiveN) current[sizeOfCurrent] = new Transistor_Inductive_Channel_MOSFET_Nchannel;
    else if(cType == _transistorInductiveP) current[sizeOfCurrent] = new Transistor_Inductive_Channel_MOSFET_Pchannel;
    else if(cType == _transistorMOSFETN) current[sizeOfCurrent] = new Transistor_MOSFET_Nchannel;
    else if(cType == _transistorMOSFETP) current[sizeOfCurrent] = new Transistor_MOSFET_Pchannel;
    else if(cType == _transistorSingleN) current[sizeOfCurrent] = new Transistor_Single_Connection_Nchannel;
    else if(cType == _transistorSingleP) current[sizeOfCurrent] = new Transistor_Single_Connection_Pchannel;
    else if(cType == _buzzer) current[sizeOfCurrent] = new Buzzer;
    else if(cType == _ground) current[sizeOfCurrent] = new Ground;
    else if(cType == _inductor) current[sizeOfCurrent] = new Inductor;
    else if(cType == _lamp) current[sizeOfCurrent] = new Lamp;
    else if(cType == _microphone) current[sizeOfCurrent] = new Microphone;
    else if(cType == _motor) current[sizeOfCurrent] = new Motor;
    else if(cType == _speaker) current[sizeOfCurrent] = new Speaker;
    else if(cType == 100) current[sizeOfCurrent] = new ConnectionNode;
    else return;

    current[sizeOfCurrent++]->setOutterBox(1);
}

ElectronicComponent* *Snapshot::getComponents() {
    return current;
}

int Snapshot::getComponentsNumber() {
    return sizeOfCurrent;
}

ElectronicComponent* Snapshot::getComponent(std::string componentCode) {
    for (int i = 0; i < sizeOfCurrent; i++) {
        if (current[i]->componentCode == componentCode) {
            return current[i];
        }
    }

    return NULL;
}

ElectronicComponent* Snapshot::getSelectedComponent(){
    for(int i = 0; i < 100; i++)
        if(current[i])
            if(current[i]->isSelected())
                return current[i];

    return NULL;
}

void Snapshot::removeComponent(std::string component_code) {
    for (int i = 0; i < sizeOfCurrent; i++) {
        if (current[i]) {
            if (current[i]->componentCode == component_code) {
                current[i]->Erase();
                current[i] = NULL;
                for (int j = i; j < sizeOfCurrent - 1; j++)
                    current[j] = current[j + 1];
                sizeOfCurrent--;
                break;
            }
        }
    }
}

void Snapshot::reset() {
    for (int i = 0; i < sizeOfCurrent; i++) {
        current[i] = NULL;
    }

    sizeOfCurrent = 0;
}

void Snapshot::saveToStream(std::ostream &stream, int i) {
    stream << Snapshot::nameToCtype(current[i]->name);
    stream << ' ';

    stream << current[i]->getComponentCode();
    stream << ' ';

    stream << current[i]->getPositionUpLeft().x;
    stream << ' ';

    stream << current[i]->getPositionUpLeft().y;
    stream << ' ';

    stream << current[i]->getPositionCenter().x;
    stream << ' ';

    stream << current[i]->getPositionCenter().y;
    stream << ' ';

    stream << current[i]->getPositionDownRight().x;
    stream << ' ';

    stream << current[i]->getPositionDownRight().y;
    stream << ' ';

    stream << current[i]->getWidth();
    stream << ' ';

    stream << current[i]->getHeight();
    stream << ' ';

    stream << current[i]->getRotationState();
    stream << ' ';

    stream << current[i]->flipped;
    stream << ' ';

    auto values = current[i]->getValues();
    if (values[0].first == "unsupported") {
        stream << "unsupported 0 unsupported 0";
    } else if (values.size() == 1) {
        stream << values[0].first << ' ' << values[0].second << " unsupported 0";
    } else {
        stream << values[0].first << ' ' << values[0].second << ' ' << values[1].first << ' ' << values[1].second;
    }

    // todo connections
}

void Snapshot::saveToFile(std::string filepath) {
    std::ofstream fout(filepath);

    for (int i = 0; i < sizeOfCurrent; i++) {
        saveToStream(fout, i);
        if (i != sizeOfCurrent - 1) fout << '\n';
    }

    fout.close();
}

void Snapshot::importFromStream(std::istream &stream) {
    Helper helper;
    int temp_int;
    double temp_double, temp_x, temp_y;
    std::string temp_string;

    //ctype
    stream >> temp_int;
    addComponent(temp_int);

    auto *component = getSelectedComponent();

    //componentCode
    stream >> temp_string;
    component->setComponentCode(temp_string);

    //positionLeft
    stream >> temp_x >> temp_y;
    component->setPositionUpLeft(helper.makeVector_2D(temp_x, temp_y));

    //positionCenter
    stream >> temp_x >> temp_y;
    component->setPositionCenter(helper.makeVector_2D(temp_x, temp_y));

    //positionRight
    stream >> temp_x >> temp_y;
    component->setPositionDownRight(helper.makeVector_2D(temp_x, temp_y));

    //width
    stream >> temp_double;
    component->setWidth(temp_double);

    //height
    stream >> temp_double;
    component->setHeight(temp_double);

    //rotate
    stream >> temp_int;
    component->rotateComponent(temp_int);

    //flipped
    stream >> temp_int;
    if (temp_int) component->flipComponent();

    //values
    stream >> temp_string >> temp_double;
    if (temp_string != "unsupported") component->setValue(temp_string, temp_double);
    stream >> temp_string >> temp_double;
    if (temp_string != "unsupported") component->setValue(temp_string, temp_double);
}

void Snapshot::importFromFile(std::string filepath) {
    std::ifstream fin(filepath);

    while (!fin.eof()) {
        importFromStream(fin);
        delay(50);
    }

    fin.close();
}

int Snapshot::nameToCtype(std::string name) {
    std::map<std::string, int> mapping = {
        {"Ceramic Capacitor", _capacitorCeramic},
        {"Electrolytic Capacitor", _capacitorElectrolyt},
        {"Trimmer Capacitor", _capacitorTrimmer},
        {"Variable Capacitor", _capacitorVariable},
        {"Avalance Diode", _diodeAvalance},
        {"Constant Current Diode", _diodeConstantCurrent},
        {"Gunn Diode", _diodeGunn},
        {"PN Junction Diode", _diodeJunction},
        {"Laser Diode", _diodeLaser},
        {"Light Emitting Diode", _diodeLightEmitting},
        {"Photo Diode", _diodePhoto},
        {"PIN Diode", _diodePin},
        {"Schottky Diode", _diodeSchottky},
        {"Shockley Diode", _diodeShockley},
        {"Transient Voltage Suppression Diode", _diodeVoltage},
        {"Tunnel Diode", _diodeTunnel},
        {"Varactor Diode", _diodeVaractor},
        {"Zener Diode", _diodeZener},
        {"And Gate", _andGate},
        {"Nand Gate", _nandGate},
        {"Nor Gate", _norGate},
        {"Not Gate", _notGate},
        {"Or Gate", _orGate},
        {"Xor Gate", _xorGate},
        {"Ammeter", _ammeter},
        {"Voltmeter", _voltmeter},
        {"Mobile Contact Potentiometer", _potentiometer},
        {"Resistor", _resistor},
        {"Mobile Contact Resistor", _resistorMobile},
        {"Mobile Contact and Stop Position Resistor", _resistorMobileStop},
        {"Variable Resistance Resistor", _resistorVariableResistance},
        {"Battery", _battery},
        {"AC Voltage Source", _sourceAC},
        {"DC Voltage Source", _sourceDC},
        {"Closed Switch", _switchClosed},
        {"DPST Switch", _switchDPST},
        {"Open Switch", _switchOpen},
        {"SPDT Switch", _switchSPDT},
        {"Telegraph Switch", _switchTelegraph},
        {"Thermal Magnetic Breaker Switch", _switchThermal},
        {"Bipolar NPN Transistor", _transistorBipolarNPN},
        {"Bipolar PNP Transistor", _transistorBipolarPNP},
        {"Dual Gate MOSFET N-channel Transistor", _transistorDualN},
        {"Dual Gate MOSFET P-channel Transistor", _transistorDualP},
        {"FET N-channel Transistor", _transistorFETN},
        {"FET P-channel Transistor", _transistorFETP},
        {"MOSFET Inductive Channel N-channel Transistor", _transistorInductiveN},
        {"MOSFET Inductive Channel P-channel Transistor", _transistorInductiveP},
        {"MOSFET N-channel Transistor", _transistorMOSFETN},
        {"MOSFET P-channel Transistor", _transistorMOSFETP},
        {"Single Connection N-channel Transistor", _transistorSingleN},
        {"Single Connection P-channel Transistor", _transistorSingleP},
        {"Buzzer", _buzzer},
        {"Ground", _ground},
        {"Inductor", _inductor},
        {"Lamp", _lamp},
        {"Microphone", _microphone},
        {"Motor", _motor},
        {"Speaker", _speaker},
        {"Connection Node", _connectionNode}
    };

    return mapping[name];
}
