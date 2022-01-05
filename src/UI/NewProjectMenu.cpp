#include "UI/NewProjectMenu.h"

#define BUTTON_HEIGHT 25
#define COMPONENT_SIZE 100

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
    isComponentSelected = false;

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (save.isCursorPointInButton())
            {

                nameFileMenu.Show();
                int code = nameFileMenu.ListenEvents();
                setcurrentwindow(this->window_code);

                bgiout << code << " " << nameFileMenu.filename << std :: endl;
                outstreamxy(windowWidth / 5, windowHeight / 4);

                bool hasExtension = strchr(nameFileMenu.filename.c_str(), '.');

                if (code)
                {
                    completeSnapshots.saveToFile(hasExtension ? nameFileMenu.filename : (nameFileMenu.filename + ".txt"));
                }

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

                bool isNotBounded = (cursorPoint.x - COMPONENT_SIZE/2) < this->rl ||
                                    (cursorPoint.y - COMPONENT_SIZE/2) < this->rt ||
                                    (cursorPoint.x + COMPONENT_SIZE/2) > this->rr ||
                                    (cursorPoint.y + COMPONENT_SIZE/2) > this->rb;
                if (isNotBounded)
                {
                    cType = _none;
                }
                if (cType == _capacitorCeramic)
                {
                    Capacitor_Ceramic cc;
                    cc.setWidth(COMPONENT_SIZE);
                    cc.setPositionCenter(pos);

                    //if (selectedComponent) {
                    selectedComponent.setOutterBox(false);
                    //}

                    cc.setOutterBox(true);

                    currentSnapshot.addComponent(cc);
                    selectedComponent = cc;

                    // std::cout << &cc << " " << selectedComponent->toString() << std::endl;
                    isComponentSelected = true;
                }
                else if (cType == _capacitorElectrolyt)
                {
                    Capacitor_Electrolytic ce;
                    ce.setWidth(COMPONENT_SIZE);
                    ce.setPositionCenter(pos);

                    // if (selectedComponent) {
                    selectedComponent.setOutterBox(false);
                    // }

                    ce.setOutterBox(true);

                    currentSnapshot.addComponent(ce);
                    selectedComponent = ce;
                    isComponentSelected = true;
                }
                else if (cType == _capacitorTrimmer)
                {
                    Capacitor_Trimmer ct;
                    ct.setWidth(COMPONENT_SIZE);
                    ct.setPositionCenter(pos);

                    // if (selectedComponent) {
                    //     selectedComponent -> setOutterBox(false);
                    // }

                    ct.setOutterBox(true);

                    currentSnapshot.addComponent(ct);
                    // selectedComponent = &ct;
                    isComponentSelected = true;
                }
                else if (cType == _capacitorVariable)
                {
                    Capacitor_Variable cv;
                    cv.setWidth(COMPONENT_SIZE);
                    cv.setPositionCenter(pos);

                    // if (selectedComponent) {
                    //     selectedComponent -> setOutterBox(false);
                    // }

                    cv.setOutterBox(true);

                    currentSnapshot.addComponent(cv);
                    //selectedComponent = &cv;

                    std::cout << &cv;
                    isComponentSelected = true;
                }
                else if (cType == _diodeAvalance)
                {
                    Diode_Avalance da;
                    da.setWidth(COMPONENT_SIZE);
                    da.setPositionCenter(pos);
                    currentSnapshot.addComponent(da);
                }
                else if (cType == _diodeConstantCurrent)
                {
                    Diode_Constant_Current dcc;
                    dcc.setWidth(COMPONENT_SIZE);
                    dcc.setPositionCenter(pos);
                    currentSnapshot.addComponent(dcc);
                }
                else if (cType == _diodeGunn)
                {
                    Diode_Gunn dg;
                    dg.setWidth(COMPONENT_SIZE);
                    dg.setPositionCenter(pos);
                    currentSnapshot.addComponent(dg);
                }
                else if (cType == _diodeJunction)
                {
                    Diode_Junction_PN dj;
                    dj.setWidth(COMPONENT_SIZE);
                    dj.setPositionCenter(pos);
                    currentSnapshot.addComponent(dj);
                }
                else if (cType == _diodeLaser)
                {
                    Diode_Laser dl;
                    dl.setWidth(COMPONENT_SIZE);
                    dl.setPositionCenter(pos);
                    currentSnapshot.addComponent(dl);
                }
                else if (cType == _diodeLightEmitting)
                {
                    Diode_Light_Emitting dle;
                    dle.setWidth(COMPONENT_SIZE);
                    dle.setPositionCenter(pos);
                    currentSnapshot.addComponent(dle);
                }
                else if (cType == _diodePhoto)
                {
                    Diode_Photo dph;
                    dph.setWidth(COMPONENT_SIZE);
                    dph.setPositionCenter(pos);
                    currentSnapshot.addComponent(dph);
                }
                else if (cType == _diodePin)
                {
                    Diode_PIN dpi;
                    dpi.setWidth(COMPONENT_SIZE);
                    dpi.setPositionCenter(pos);
                    currentSnapshot.addComponent(dpi);
                }
                else if (cType == _diodeSchottky)
                {
                    Diode_Schottky dsc;
                    dsc.setWidth(COMPONENT_SIZE);
                    dsc.setPositionCenter(pos);
                    currentSnapshot.addComponent(dsc);
                }
                else if (cType == _diodeShockley)
                {
                    Diode_Shockley dsh;
                    dsh.setWidth(COMPONENT_SIZE);
                    dsh.setPositionCenter(pos);
                    currentSnapshot.addComponent(dsh);
                }
                else if (cType == _diodeVoltage)
                {
                    Diode_Transient_Voltage_Suppression dvo;
                    dvo.setWidth(COMPONENT_SIZE);
                    dvo.setPositionCenter(pos);
                    currentSnapshot.addComponent(dvo);
                }
                else if (cType == _diodeTunnel)
                {
                    Diode_Tunnel dt;
                    dt.setWidth(COMPONENT_SIZE);
                    dt.setPositionCenter(pos);
                    currentSnapshot.addComponent(dt);
                }
                else if (cType == _diodeVaractor)
                {
                    Diode_Varactor dv;
                    dv.setWidth(COMPONENT_SIZE);
                    dv.setPositionCenter(pos);
                    currentSnapshot.addComponent(dv);
                }
                else if (cType == _diodeZener)
                {
                    Diode_Zener dz;
                    dz.setWidth(COMPONENT_SIZE);
                    dz.setPositionCenter(pos);
                    currentSnapshot.addComponent(dz);
                }
                else if (cType == _andGate)
                {
                    AndGate ag;
                    ag.setWidth(COMPONENT_SIZE);
                    ag.setPositionCenter(pos);
                    currentSnapshot.addComponent(ag);
                }
                else if (cType == _nandGate)
                {
                    NandGate nag;
                    nag.setWidth(COMPONENT_SIZE);
                    nag.setPositionCenter(pos);
                    currentSnapshot.addComponent(nag);
                }
                else if (cType == _norGate)
                {
                    NorGate norg;
                    norg.setWidth(COMPONENT_SIZE);
                    norg.setPositionCenter(pos);
                    currentSnapshot.addComponent(norg);
                }
                else if (cType == _notGate)
                {
                    NotGate notg;
                    notg.setWidth(COMPONENT_SIZE);
                    notg.setPositionCenter(pos);
                    currentSnapshot.addComponent(notg);
                }
                else if (cType == _orGate)
                {
                    OrGate og;
                    og.setWidth(COMPONENT_SIZE);
                    og.setPositionCenter(pos);
                    currentSnapshot.addComponent(og);
                }
                else if (cType == _xorGate)
                {
                    XorGate xg;
                    xg.setWidth(COMPONENT_SIZE);
                    xg.setPositionCenter(pos);
                    currentSnapshot.addComponent(xg);
                }
                else if (cType == _ammeter)
                {
                    Ammeter a;
                    a.setWidth(COMPONENT_SIZE);
                    a.setPositionCenter(pos);
                    currentSnapshot.addComponent(a);
                }
                else if (cType == _voltmeter)
                {
                    Voltmeter v;
                    v.setWidth(COMPONENT_SIZE);
                    v.setPositionCenter(pos);
                    currentSnapshot.addComponent(v);
                }
                else if (cType == _buzzer)
                {
                    Buzzer b;
                    b.setWidth(COMPONENT_SIZE);
                    b.setPositionCenter(pos);
                    currentSnapshot.addComponent(b);
                }
                else if (cType == _ground)
                {
                    Ground g;
                    g.setWidth(COMPONENT_SIZE);
                    g.setPositionCenter(pos);
                    currentSnapshot.addComponent(g);
                }
                else if (cType == _inductor)
                {
                    Inductor i;
                    i.setWidth(COMPONENT_SIZE);
                    i.setPositionCenter(pos);
                    currentSnapshot.addComponent(i);
                }
                else if (cType == _lamp)
                {
                    Lamp l;
                    l.setWidth(COMPONENT_SIZE);
                    l.setPositionCenter(pos);
                    currentSnapshot.addComponent(l);
                }
                else if (cType == _microphone)
                {
                    Microphone mi;
                    mi.setWidth(COMPONENT_SIZE);
                    mi.setPositionCenter(pos);
                    currentSnapshot.addComponent(mi);
                }
                else if (cType == _motor)
                {
                    Motor mo;
                    mo.setWidth(COMPONENT_SIZE);
                    mo.setPositionCenter(pos);
                    currentSnapshot.addComponent(mo);
                }
                else if (cType == _speaker)
                {
                    Speaker s;
                    s.setWidth(COMPONENT_SIZE);
                    s.setPositionCenter(pos);
                    currentSnapshot.addComponent(s);
                }
                else if (cType == _potentiometer)
                {
                    Potentiometer_Mobile_Contact pmc;
                    pmc.setWidth(COMPONENT_SIZE);
                    pmc.setPositionCenter(pos);
                    currentSnapshot.addComponent(pmc);
                }
                else if (cType == _resistorMobileStop)
                {
                    Resistor_Mobile_Contact_Stop_Position rms;
                    rms.setWidth(COMPONENT_SIZE);
                    rms.setPositionCenter(pos);
                    currentSnapshot.addComponent(rms);
                }
                else if (cType == _resistorMobile)
                {
                    Resistor_Mobile_Contact rm;
                    rm.setWidth(COMPONENT_SIZE);
                    rm.setPositionCenter(pos);
                    currentSnapshot.addComponent(rm);
                }
                else if (cType == _resistorVariableResistance)
                {
                    Resistor_Variable_Resistance rvr;
                    rvr.setWidth(COMPONENT_SIZE);
                    rvr.setPositionCenter(pos);
                    currentSnapshot.addComponent(rvr);
                }
                else if (cType == _resistor)
                {
                    Resistor r;
                    r.setWidth(COMPONENT_SIZE);
                    r.setPositionCenter(pos);
                    currentSnapshot.addComponent(r);
                }
                else if (cType == _sourceAC)
                {
                    Source_Voltage_AC sac;
                    sac.setWidth(COMPONENT_SIZE);
                    sac.setPositionCenter(pos);
                    currentSnapshot.addComponent(sac);
                }
                else if (cType == _sourceDC)
                {
                    Source_Voltage_DC sdc;
                    sdc.setWidth(COMPONENT_SIZE);
                    sdc.setPositionCenter(pos);
                    currentSnapshot.addComponent(sdc);
                }
                else if (cType == _battery)
                {
                    Battery bat;
                    bat.setWidth(COMPONENT_SIZE);
                    bat.setPositionCenter(pos);
                    currentSnapshot.addComponent(bat);
                }
                else if (cType == _switchClosed)
                {
                    Switch_Closed sc;
                    sc.setWidth(COMPONENT_SIZE);
                    sc.setPositionCenter(pos);
                    currentSnapshot.addComponent(sc);
                }
                else if (cType == _switchSPDT)
                {
                    Switch_SPDT sspdt;
                    sspdt.setWidth(COMPONENT_SIZE);
                    sspdt.setPositionCenter(pos);
                    currentSnapshot.addComponent(sspdt);
                }
                else if (cType == _switchOpen)
                {
                    Switch_Open so;
                    so.setWidth(COMPONENT_SIZE);
                    so.setPositionCenter(pos);
                    currentSnapshot.addComponent(so);
                }
                else if (cType == _switchDPST)
                {
                    Switch_DPST sdpst;
                    sdpst.setWidth(COMPONENT_SIZE);
                    sdpst.setPositionCenter(pos);
                    currentSnapshot.addComponent(sdpst);
                }
                else if (cType == _switchTelegraph)
                {
                    Switch_Telegraph st;
                    st.setWidth(COMPONENT_SIZE);
                    st.setPositionCenter(pos);
                    currentSnapshot.addComponent(st);
                }
                else if (cType == _switchThermal)
                {
                    Switch_Thermal_Magnetic_Breaker stmb;
                    stmb.setWidth(COMPONENT_SIZE);
                    stmb.setPositionCenter(pos);
                    currentSnapshot.addComponent(stmb);
                }
                else if (cType == _transistorBipolarNPN)
                {
                    Transistor_Bipolar_NPN tbn;
                    tbn.setWidth(COMPONENT_SIZE);
                    tbn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tbn);
                }
                else if (cType == _transistorBipolarPNP)
                {
                    Transistor_Bipolar_PNP tbp;
                    tbp.setWidth(COMPONENT_SIZE);
                    tbp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tbp);
                }
                else if (cType == _transistorDualN)
                {
                    Transistor_Dual_Gate_MOSFET_Nchannel tdn;
                    tdn.setWidth(COMPONENT_SIZE);
                    tdn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tdn);
                }
                else if (cType == _transistorDualP)
                {
                    Transistor_Dual_Gate_MOSFET_Pchannel tdp;
                    tdp.setWidth(COMPONENT_SIZE);
                    tdp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tdp);
                }
                else if (cType == _transistorFETN)
                {
                    Transistor_FET_Nchannel tfn;
                    tfn.setWidth(COMPONENT_SIZE);
                    tfn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tfn);
                }
                else if (cType == _transistorFETP)
                {
                    Transistor_FET_Pchannel tfp;
                    tfp.setWidth(COMPONENT_SIZE);
                    tfp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tfp);
                }
                else if (cType == _transistorInductiveN)
                {
                    Transistor_Inductive_Channel_MOSFET_Nchannel tim;
                    tim.setWidth(COMPONENT_SIZE);
                    tim.setPositionCenter(pos);
                    currentSnapshot.addComponent(tim);
                }
                else if (cType == _transistorInductiveP)
                {
                    Transistor_Inductive_Channel_MOSFET_Pchannel tip;
                    tip.setWidth(COMPONENT_SIZE);
                    tip.setPositionCenter(pos);
                    currentSnapshot.addComponent(tip);
                }
                else if (cType == _transistorMOSFETN)
                {
                    Transistor_MOSFET_Nchannel tmn;
                    tmn.setWidth(COMPONENT_SIZE);
                    tmn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tmn);
                }
                else if (cType == _transistorMOSFETP)
                {
                    Transistor_MOSFET_Pchannel tmp;
                    tmp.setWidth(COMPONENT_SIZE);
                    tmp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tmp);
                }
                else if (cType == _transistorSingleN)
                {
                    Transistor_Single_Connection_Nchannel tsn;
                    tsn.setWidth(COMPONENT_SIZE);
                    tsn.setPositionCenter(pos);
                    currentSnapshot.addComponent(tsn);
                }
                else if (cType == _transistorSingleP)
                {
                    Transistor_Single_Connection_Pchannel tsp;
                    tsp.setWidth(COMPONENT_SIZE);
                    tsp.setPositionCenter(pos);
                    currentSnapshot.addComponent(tsp);
                }
                //completeSnapshots.setCurrent(currentSnapshot);
                cType = _none;
            }
            else if (cType == _none)
            {
                //will move the component
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                Helper::Vector_2D pos = helper.makeVector_2D(cursorPoint.x, cursorPoint.y);

                std :: cout << pos.x << " " << pos.y << std :: endl;
            }

            if (flip_h.isCursorPointInButton())
            {
                selectedComponent.flipComponent();
            }
            if (flip_v.isCursorPointInButton())
            {
                selectedComponent.rotateComponent(180);
                delay(300);
                selectedComponent.flipComponent();
            }
            if (rotate_l.isCursorPointInButton())
            {
                selectedComponent.rotateComponent(345);
            }
            if (rotate_r.isCursorPointInButton())
            {
                selectedComponent.rotateComponent(15);
            }
            if (inc.isCursorPointInButton())
            {
                selectedComponent.setWidth(selectedComponent.getWidth() + 5);
            }
            if (dec.isCursorPointInButton())
            {
                selectedComponent.setWidth(selectedComponent.getWidth() - 5);
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
    double BUTTON_WIDTH = (windowWidth - 50) / 10;

    this->rl = BUTTON_WIDTH * 2,  this->rt = BUTTON_HEIGHT * 3,
          this->rr = windowWidth - BUTTON_WIDTH * 2, this->rb = windowHeight - 3 * BUTTON_HEIGHT;

    rectangle(this->rl, this->rt, this->rr, this->rb);

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

    double r = 25;

    rotate_l.setPositionCenter(helper.makeVector_2D(this->rr + 3*r, this->rb - 5*r));
    rotate_l.setWidth(r);
    rotate_l.setHeight(r);
    rotate_l.setTitle("R<-");
    rotate_l.ShowCircleMode();

    rotate_r.setPositionCenter(helper.makeVector_2D(this->rr + 6*r, this->rb - 5*r));
    rotate_r.setWidth(r);
    rotate_r.setHeight(r);
    rotate_r.setTitle("R->");
    rotate_r.ShowCircleMode();

    flip_h.setPositionCenter(helper.makeVector_2D(this->rr + 3*r, this->rb - r));
    flip_h.setWidth(r);
    flip_h.setHeight(r);
    flip_h.setTitle("F<|>");
    flip_h.ShowCircleMode();

    flip_v.setPositionCenter(helper.makeVector_2D(this->rr + 6*r, this->rb -r));
    flip_v.setWidth(r);
    flip_v.setHeight(r);
    flip_v.setTitle("F<->");
    flip_v.ShowCircleMode();

    inc.setPositionCenter(helper.makeVector_2D(this->rl - 3*r, this->rb - 5*r));
    inc.setWidth(r);
    inc.setHeight(r);
    inc.setTitle("+");
    inc.ShowCircleMode();

    dec.setPositionCenter(helper.makeVector_2D(this->rl - 6*r, this->rb - 5*r));
    dec.setWidth(r);
    dec.setHeight(r);
    dec.setTitle("-");
    dec.ShowCircleMode();
}
