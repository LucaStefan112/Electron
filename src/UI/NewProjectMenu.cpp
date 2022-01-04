#include "UI/NewProjectMenu.h"

#define BUTTON_HEIGHT 25

NewProjectMenu::NewProjectMenu()
{
    //ctor
}

void NewProjectMenu::WatchClick()
{
    int ok = 1;

    Helper helper;
    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    int cType = _none;

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (save.isCursorPointInButton())
            {
                std::cout << "saving data ..." << std::endl;
                completeSnapshots.saveToFile("file.txt");
            }
            else if (capacitors.isCursorPointInButton())
            {
                std::cout << "capacitors" << std::endl;
                CapacitorsInfo capacitorsInfo;
                capacitorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = capacitorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (diodes.isCursorPointInButton())
            {
                std::cout << "diodes" << std::endl;
                DiodesInfo diodesInfo;
                diodesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 9));
                cType = diodesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (logicGates.isCursorPointInButton())
            {
                std::cout << "logic gates" << std::endl;
                LogicGatesInfo logicGatesInfo;
                logicGatesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = logicGatesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (measurements.isCursorPointInButton())
            {
                std::cout << "measurements" << std::endl;
                MeasurementsInfo measurementsInfo;
                measurementsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 2));
                cType = measurementsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (resistors.isCursorPointInButton())
            {
                std::cout << "resistors" << std::endl;
                ResistorsInfo resistorsInfo;
                resistorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 6));
                cType = resistorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (sources.isCursorPointInButton())
            {
                std::cout << "sources" << std::endl;
                SourcesInfo sourcesInfo;
                sourcesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = sourcesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (switches.isCursorPointInButton())
            {
                std::cout << "switches" << std::endl;
                SwitchesInfo switchesInfo;
                switchesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = switchesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (transistors.isCursorPointInButton())
            {
                std::cout << "transistors" << std::endl;
                TransistorsInfo transistorsInfo;
                transistorsInfo.Show((double)(windowWidth / 8), (double)(windowHeight / 8));
                cType = transistorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (other.isCursorPointInButton())
            {
                std::cout << "other" << std::endl;
                OtherInfo otherInfo;
                otherInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = otherInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (exit.isCursorPointInButton())
            {
                ok = 0;
            }
            else if (cType != _none)
            {
                std ::cout << "i m here " << cType << std ::endl;
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                Helper::Vector_2D pos = helper.makeVector_2D(cursorPoint.x, cursorPoint.y);

                if (cType == _capacitorCeramic) {
                    Capacitor_Ceramic cc;
                    cc.setWidth(100);
                    cc.setPositionCenter(pos);

                    currentSnapshot.addComponent(cc);
                } else if (cType == _capacitorElectrolyt) {
                    Capacitor_Electrolytic ce;
                    ce.setWidth(100);
                    ce.setPositionCenter(pos);

                    currentSnapshot.addComponent(ce);
                } else if (cType == _capacitorTrimmer) {
                    Capacitor_Trimmer ct;
                    ct.setWidth(100);
                    ct.setPositionCenter(pos);
                    currentSnapshot.addComponent(ct);
                } else if (cType == _capacitorVariable) {
                    Capacitor_Variable cv;
                    cv.setWidth(100);
                    cv.setPositionCenter(pos);
                    currentSnapshot.addComponent(cv);
                } else if (cType == _diodeAvalance) {
                    Diode_Avalance da;
                    da.setWidth(100);
                    da.setPositionCenter(pos);
                    currentSnapshot.addComponent(da);
                } else if (cType == _diodeConstantCurrent) {
                    Diode_Constant_Current dcc;
                    dcc.setWidth(100);
                    dcc.setPositionCenter(pos);
                    currentSnapshot.addComponent(dcc);
                } else if (cType == _diodeGunn) {
                    Diode_Gunn dg;
                    dg.setWidth(100);
                    dg.setPositionCenter(pos);
                    currentSnapshot.addComponent(dg);
                } else if (cType == _diodeJunction) {
                    Diode_Junction_PN dj;
                    dj.setWidth(100);
                    dj.setPositionCenter(pos);
                    currentSnapshot.addComponent(dj);
                } else if (cType == _diodeLaser) {
                    Diode_Laser dl;
                    dl.setWidth(100);
                    dl.setPositionCenter(pos);
                    currentSnapshot.addComponent(dl);
                } else if (cType == _diodeLightEmitting) {
                    Diode_Light_Emitting dle;
                    dle.setWidth(100);
                    dle.setPositionCenter(pos);
                    currentSnapshot.addComponent(dle);
                } else if (cType == _diodePhoto) {
                    Diode_Photo dph;
                    dph.setWidth(100);
                    dph.setPositionCenter(pos);
                    currentSnapshot.addComponent(dph);
                } else if (cType == _diodePin) {
                    Diode_PIN dpi;
                    dpi.setWidth(100);
                    dpi.setPositionCenter(pos);
                    currentSnapshot.addComponent(dpi);
                } else if (cType == _diodeSchottky) {
                    Diode_Schottky dsc;
                    dsc.setWidth(100);
                    dsc.setPositionCenter(pos);
                    currentSnapshot.addComponent(dsc);
                } else if (cType == _diodeShockley) {
                    Diode_Shockley dsh;
                    dsh.setWidth(100);
                    dsh.setPositionCenter(pos);
                    currentSnapshot.addComponent(dsh);
                } else if (cType == _diodeVoltage) {
                    Diode_Transient_Voltage_Suppression dvo;
                    dvo.setWidth(100);
                    dvo.setPositionCenter(pos);
                    currentSnapshot.addComponent(dvo);
                } else if (cType == _diodeTunnel) {
                    Diode_Tunnel dt;
                    dt.setWidth(100);
                    dt.setPositionCenter(pos);
                    currentSnapshot.addComponent(dt);
                } else if (cType == _diodeVaractor) {
                    Diode_Varactor dv;
                    dv.setWidth(100);
                    dv.setPositionCenter(pos);
                    currentSnapshot.addComponent(dv);
                } else if (cType == _diodeZener) {
                    Diode_Zener dz;
                    dz.setWidth(100);
                    dz.setPositionCenter(pos);
                    currentSnapshot.addComponent(dz);
                } else if (cType == _andGate) {
                    AndGate ag;
                    ag.setWidth(100);
                    ag.setPositionCenter(pos);
                    currentSnapshot.addComponent(ag);
                } else if (cType == _nandGate) {
                    NandGate nag;
                    nag.setWidth(100);
                    nag.setPositionCenter(pos);
                    currentSnapshot.addComponent(nag);
                } else if (cType == _norGate) {
                    NorGate norg;
                    norg.setWidth(100);
                    norg.setPositionCenter(pos);
                    currentSnapshot.addComponent(norg);
                } else if (cType == _notGate) {
                    NotGate notg;
                    notg.setWidth(100);
                    notg.setPositionCenter(pos);
                    currentSnapshot.addComponent(notg);
                } else if (cType == _orGate) {
                    OrGate og;
                    og.setWidth(100);
                    og.setPositionCenter(pos);
                    currentSnapshot.addComponent(og);
                } else if (cType == _xorGate) {
                    XorGate xg;
                    xg.setWidth(100);
                    xg.setPositionCenter(pos);
                    currentSnapshot.addComponent(xg);
                } else if (cType == _ammeter) {
                    Ammeter a;
                    a.setWidth(100);
                    a.setPositionCenter(pos);
                    currentSnapshot.addComponent(a);
                } else if (cType == _voltmeter) {
                    Voltmeter v;
                    v.setWidth(100);
                    v.setPositionCenter(pos);
                    currentSnapshot.addComponent(v);
                } else if (cType == _buzzer) {
                    Buzzer b;
                    b.setWidth(100);
                    b.setPositionCenter(pos);
                    currentSnapshot.addComponent(b);
                } else if (cType == _ground) {
                    Ground g;
                    g.setWidth(100);
                    g.setPositionCenter(pos);
                    currentSnapshot.addComponent(g);
                } else if (cType == _inductor) {
                    Inductor i;
                    i.setWidth(100);
                    i.setPositionCenter(pos);
                    currentSnapshot.addComponent(i);
                } else if (cType == _lamp) {
                    Lamp l;
                    l.setWidth(100);
                    l.setPositionCenter(pos);
                    currentSnapshot.addComponent(l);
                } else if (cType == _microphone) {
                    Microphone mi;
                    mi.setWidth(100);
                    mi.setPositionCenter(pos);
                    currentSnapshot.addComponent(mi);
                } else if (cType == _motor) {
                    Motor mo;
                    mo.setWidth(100);
                    mo.setPositionCenter(pos);
                    currentSnapshot.addComponent(mo);
                } else if (cType == _speaker) {
                    Speaker s;
                    s.setWidth(100);
                    s.setPositionCenter(pos);
                    currentSnapshot.addComponent(s);
                } else if (cType == _potentiometer) {
                    Potentiometer_Mobile_Contact pmc;
                    pmc.setWidth(100);
                    pmc.setPositionCenter(pos);
                    currentSnapshot.addComponent(pmc);
                } else if (cType == _resistorMobileStop) {
                    Resistor_Mobile_Contact_Stop_Position rms;
                    rms.setWidth(100);
                    rms.setPositionCenter(pos);
                    currentSnapshot.addComponent(rms);
                } else if (cType == _resistorMobile) {
                    Resistor_Mobile_Contact rm;
                    rm.setWidth(100);
                    rm.setPositionCenter(pos);
                    currentSnapshot.addComponent(rm);
                } else if (cType == _resistorVariableResistance) {
                    Resistor_Variable_Resistance rvr;
                    rvr.setWidth(100);
                    rvr.setPositionCenter(pos);
                    currentSnapshot.addComponent(rvr);
                } else if (cType == _resistor) {
                    Resistor r;
                    r.setWidth(100);
                    r.setPositionCenter(pos);
                    currentSnapshot.addComponent(r);
                } else if (cType == _sourceAC) {
                    Source_Voltage_AC sac;
                    sac.setWidth(100);
                    sac.setPositionCenter(pos);
                    currentSnapshot.addComponent(sac);
                } else if (cType == _sourceDC) {
                    Source_Voltage_DC sdc;
                    sdc.setWidth(100);
                    sdc.setPositionCenter(pos);
                    currentSnapshot.addComponent(sdc);
                } else if (cType == _battery) {
                    Battery bat;
                    bat.setWidth(100);
                    bat.setPositionCenter(pos);
                    currentSnapshot.addComponent(bat);
                } else if (cType == _switchClosed) {
                    Switch_Closed sc;
                    sc.setWidth(100);
                    sc.setPositionCenter(pos);
                    currentSnapshot.addComponent(sc);
                } else if (cType == _switchSPDT) {
                    Switch_SPDT sspdt;
                    sspdt.setWidth(100);
                    sspdt.setPositionCenter(pos);
                    currentSnapshot.addComponent(sspdt);
                } else if (cType == _switchOpen) {
                    Switch_Open so;
                    so.setWidth(100);
                    so.setPositionCenter(pos);
                    currentSnapshot.addComponent(so);
                } else if (cType == _switchDPST) {
                    Switch_DPST sdpst;
                    sdpst.setWidth(100);
                    sdpst.setPositionCenter(pos);
                    currentSnapshot.addComponent(sdpst);
                } else if (cType == _switchTelegraph) {
                    Switch_Telegraph st;
                    st.setWidth(100);
                    st.setPositionCenter(pos);
                    currentSnapshot.addComponent(st);
                } else if (cType == _switchThermal) {
                    Switch_Thermal_Magnetic_Breaker stmb;
                    stmb.setWidth(100);
                    stmb.setPositionCenter(pos);
                    currentSnapshot.addComponent(stmb);
                } else if (cType == _transistorBipolarNPN) {
                    Transistor_Bipolar_NPN tbn;
                    tbn.setWidth(100);
                    tbn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tbn);
                } else if (cType == _transistorBipolarPNP) {
                    Transistor_Bipolar_PNP tbp;
                    tbp.setWidth(100);
                    tbp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tbp);
                } else if (cType == _transistorDualN) {
                    Transistor_Dual_Gate_MOSFET_Nchannel tdn;
                    tdn.setWidth(100);
                    tdn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tdn);
                } else if (cType == _transistorDualP) {
                    Transistor_Dual_Gate_MOSFET_Pchannel tdp;
                    tdp.setWidth(100);
                    tdp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tdp);
                } else if (cType == _transistorFETN) {
                    Transistor_FET_Nchannel tfn;
                    tfn.setWidth(100);
                    tfn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tfn);
                } else if (cType == _transistorFETP) {
                    Transistor_FET_Pchannel tfp;
                    tfp.setWidth(100);
                    tfp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tfp);
                } else if (cType == _transistorInductiveN) {
                    Transistor_Inductive_Channel_MOSFET_Nchannel tim;
                    tim.setWidth(100);
                    tim.setPositionCenter(pos);
                    currentSnapshot.addComponent(tim);
                } else if (cType == _transistorInductiveP) {
                    Transistor_Inductive_Channel_MOSFET_Pchannel tip;
                    tip.setWidth(100);
                    tip.setPositionCenter(pos);
                    currentSnapshot.addComponent(tip);
                } else if (cType == _transistorMOSFETN) {
                    Transistor_MOSFET_Nchannel tmn;
                    tmn.setWidth(100);
                    tmn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tmn);
                } else if (cType == _transistorMOSFETP) {
                    Transistor_MOSFET_Pchannel tmp;
                    tmp.setWidth(100);
                    tmp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tmp);
                } else if (cType == _transistorSingleN) {
                    Transistor_Single_Connection_Nchannel tsn;
                    tsn.setWidth(100);
                    tsn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tsn);
                } else if (cType == _transistorSingleP) {
                    Transistor_Single_Connection_Pchannel tsp;
                    tsp.setWidth(100);
                    tsp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tsp);
                }
                completeSnapshots.setCurrent(currentSnapshot);
                cType = _none;
            }
        }
        delay(500);
    }
    delay(500);
    closegraph(this->window_code);
}

void NewProjectMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth, screenHeight, "", -3, -3);
    this->window_code = wc;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();
    double BUTTON_WIDTH = (windowWidth - 75) / 10;

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(BUTTON_HEIGHT);
    exit.setTitle("Exit");
    exit.Show();

    save.setPositionUpLeft(helper.makeVector_2D(75, 0));
    save.setWidth(BUTTON_WIDTH);
    save.setHeight(BUTTON_HEIGHT);
    save.setTitle("Save");
    save.Show();

    capacitors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH + 75, 0));
    capacitors.setWidth(BUTTON_WIDTH);
    capacitors.setHeight(BUTTON_HEIGHT);
    capacitors.setTitle("Capacitors");
    capacitors.Show();

    diodes.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 2 + 75, 0));
    diodes.setWidth(BUTTON_WIDTH);
    diodes.setHeight(BUTTON_HEIGHT);
    diodes.setTitle("Diodes");
    diodes.Show();

    logicGates.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 3 + 75, 0));
    logicGates.setWidth(BUTTON_WIDTH);
    logicGates.setHeight(BUTTON_HEIGHT);
    logicGates.setTitle("Logic Gates");
    logicGates.Show();

    measurements.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 4 + 75, 0));
    measurements.setWidth(BUTTON_WIDTH);
    measurements.setHeight(BUTTON_HEIGHT);
    measurements.setTitle("Measurements");
    measurements.Show();

    resistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 5 + 75, 0));
    resistors.setWidth(BUTTON_WIDTH);
    resistors.setHeight(BUTTON_HEIGHT);
    resistors.setTitle("Resistors");
    resistors.Show();

    sources.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 6 + 75, 0));
    sources.setWidth(BUTTON_WIDTH);
    sources.setHeight(BUTTON_HEIGHT);
    sources.setTitle("Sources");
    sources.Show();

    switches.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 7 + 75, 0));
    switches.setWidth(BUTTON_WIDTH);
    switches.setHeight(BUTTON_HEIGHT);
    switches.setTitle("Switches");
    switches.Show();

    transistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 8 + 75, 0));
    transistors.setWidth(BUTTON_WIDTH);
    transistors.setHeight(BUTTON_HEIGHT);
    transistors.setTitle("Transistors");
    transistors.Show();

    other.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 9 + 75, 0));
    other.setWidth(BUTTON_WIDTH);
    other.setHeight(BUTTON_HEIGHT);
    other.setTitle("Other");
    other.Show();
}
