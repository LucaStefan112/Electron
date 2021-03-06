#ifndef ENUMS_H
#define ENUMS_H

//daria
enum PositionType
{
    up_left,
    center,
    down_right
};

enum ComponentType
{
    _none,
    _capacitorCeramic,
    _capacitorElectrolyt,
    _capacitorTrimmer,
    _capacitorVariable,
    _diodeAvalance,
    _diodeConstantCurrent,
    _diodeGunn,
    _diodeJunction,
    _diodeLaser,
    _diodeLightEmitting,
    _diodePhoto,
    _diodePin,
    _diodeSchottky,
    _diodeShockley,
    _diodeVoltage,
    _diodeTunnel,
    _diodeVaractor,
    _diodeZener,
    _andGate,
    _nandGate,
    _norGate,
    _notGate,
    _orGate,
    _xorGate,
    _ammeter,
    _voltmeter,
    _buzzer,
    _ground,
    _inductor,
    _lamp,
    _microphone,
    _motor,
    _speaker,
    _potentiometer,
    _resistorMobileStop,
    _resistorMobile,
    _resistorVariableResistance,
    _resistor,
    _sourceAC,
    _sourceDC,
    _battery,
    _switchClosed,
    _switchSPDT,
    _switchOpen,
    _switchDPST,
    _switchTelegraph,
    _switchThermal,
    _transistorBipolarNPN,
    _transistorBipolarPNP,
    _transistorDualN,
    _transistorDualP,
    _transistorFETN,
    _transistorFETP,
    _transistorInductiveN,
    _transistorInductiveP,
    _transistorMOSFETN,
    _transistorMOSFETP,
    _transistorSingleN,
    _transistorSingleP,
    _connectionNode
};

#endif // ENUMS_H
