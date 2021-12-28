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

    clearmouseclick(WM_LBUTTONDOWN);
    while (ok)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (save.isCursorPointInButton())
            {
                std::cout << "saving data ..." << std::endl;
            }
            if (capacitors.isCursorPointInButton())
            {
                std::cout << "capacitors" << std::endl;
                CapacitorsInfo capacitorsInfo;
                capacitorsInfo.CreateScreen();
                capacitorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = capacitorsInfo.WatchClick();
            }
            if (diodes.isCursorPointInButton())
            {
                DiodesInfo diodesInfo;
                diodesInfo.CreateScreen();
                diodesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 9));
            }
            if (logicGates.isCursorPointInButton())
            {
                LogicGatesInfo logicGatesInfo;
                logicGatesInfo.CreateScreen();
                logicGatesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
            }
            if (measurements.isCursorPointInButton())
            {
                MeasurementsInfo measurementsInfo;
                measurementsInfo.CreateScreen();
                measurementsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 2));
            }
            if (resistors.isCursorPointInButton())
            {
                ResistorsInfo resistorsInfo;
                resistorsInfo.CreateScreen();
                resistorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 6));
            }
            if (sources.isCursorPointInButton())
            {
                SourcesInfo sourcesInfo;
                sourcesInfo.CreateScreen();
                sourcesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
            }
            if (switches.isCursorPointInButton())
            {
                SwitchesInfo switchesInfo;
                switchesInfo.CreateScreen();
                switchesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
            }
            if (transistors.isCursorPointInButton())
            {
                TransistorsInfo transistorsInfo;
                transistorsInfo.CreateScreen();
                transistorsInfo.Show((double)(windowWidth / 8), (double)(windowHeight / 8));
            }
            if (other.isCursorPointInButton())
            {
                OtherInfo otherInfo;
                otherInfo.CreateScreen();
                otherInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
            }
            if (exit.isCursorPointInButton())
            {
                ok = 0;
                closegraph(CURRENT_WINDOW);
            }

            POINT cursorPoint;
            GetCursorPos(&cursorPoint);

            if (cType == _capacitorCeramic)
            {
                Capacitor_Ceramic cc;
                cc.setWidth(100);
                cc.setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                cc.Show();
            }

            if (cType == _capacitorElectrolyt)
            {
                Capacitor_Electrolytic ce;
                ce.setWidth(100);
                ce.setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                ce.Show();
            }
            if (cType == _capacitorTrimmer)
            {
                Capacitor_Trimmer ct;
                ct.setWidth(100);
                ct.setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                ct.Show();
            }
            if (cType == _capacitorVariable)
            {
                Capacitor_Variable cv;
                cv.setWidth(100);
                cv.setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                cv.Show();
            }
        }
        delay(200);
    }
}

void NewProjectMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth/2, screenHeight/2, "", -3, -3);

    int windowWidth = getwindowwidth();
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

    capacitors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH+75, 0));
    capacitors.setWidth(BUTTON_WIDTH);
    capacitors.setHeight(BUTTON_HEIGHT);
    capacitors.setTitle("Capacitors");
    capacitors.Show();

    diodes.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*2+75, 0));
    diodes.setWidth(BUTTON_WIDTH);
    diodes.setHeight(BUTTON_HEIGHT);
    diodes.setTitle("Diodes");
    diodes.Show();

    logicGates.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*3+75, 0));
    logicGates.setWidth(BUTTON_WIDTH);
    logicGates.setHeight(BUTTON_HEIGHT);
    logicGates.setTitle("Logic Gates");
    logicGates.Show();

    measurements.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*4+75, 0));
    measurements.setWidth(BUTTON_WIDTH);
    measurements.setHeight(BUTTON_HEIGHT);
    measurements.setTitle("Measurements");
    measurements.Show();

    resistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*5+75, 0));
    resistors.setWidth(BUTTON_WIDTH);
    resistors.setHeight(BUTTON_HEIGHT);
    resistors.setTitle("Resistors");
    resistors.Show();

    sources.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*6+75, 0));
    sources.setWidth(BUTTON_WIDTH);
    sources.setHeight(BUTTON_HEIGHT);
    sources.setTitle("Sources");
    sources.Show();

    switches.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*7+75, 0));
    switches.setWidth(BUTTON_WIDTH);
    switches.setHeight(BUTTON_HEIGHT);
    switches.setTitle("Switches");
    switches.Show();

    transistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*8+75, 0));
    transistors.setWidth(BUTTON_WIDTH);
    transistors.setHeight(BUTTON_HEIGHT);
    transistors.setTitle("Transistors");
    transistors.Show();

    other.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH*9+75, 0));
    other.setWidth(BUTTON_WIDTH);
    other.setHeight(BUTTON_HEIGHT);
    other.setTitle("Other");
    other.Show();
}
