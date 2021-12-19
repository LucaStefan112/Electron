#include "UI/InfoMenu.h"
#include "Helper.h"

#define BUTTON_HEIGHT 30

InfoMenu::InfoMenu()
{
    //ctor
}
void InfoMenu::WatchClick()
{
    int ok = 1;

    Helper helper;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (capacitors.isCursorPointInButton())
            {
                CapacitorsInfo capacitorsInfo;
                capacitorsInfo.CreateScreen();
                capacitorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                capacitorsInfo.AddExit();
            }
            if (diodes.isCursorPointInButton())
            {
                DiodesInfo diodesInfo;
                diodesInfo.CreateScreen();
                diodesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 9));
                diodesInfo.AddExit();
            }
            if (logicGates.isCursorPointInButton())
            {
                LogicGatesInfo logicGatesInfo;
                logicGatesInfo.CreateScreen();
                logicGatesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                logicGatesInfo.AddExit();
            }
            if (measurements.isCursorPointInButton())
            {
                MeasurementsInfo measurementsInfo;
                measurementsInfo.CreateScreen();
                measurementsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 2));
                measurementsInfo.AddExit();
            }
            if (resistors.isCursorPointInButton())
            {
                ResistorsInfo resistorsInfo;
                resistorsInfo.CreateScreen();
                resistorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 6));
                resistorsInfo.AddExit();
            }
            if (sources.isCursorPointInButton())
            {
                SourcesInfo sourcesInfo;
                sourcesInfo.CreateScreen();
                sourcesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                sourcesInfo.AddExit();
            }
            if (switches.isCursorPointInButton())
            {
                SwitchesInfo switchesInfo;
                switchesInfo.CreateScreen();
                switchesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                switchesInfo.AddExit();
            }
            if (transistors.isCursorPointInButton())
            {
                TransistorsInfo transistorsInfo;
                transistorsInfo.CreateScreen();
                transistorsInfo.Show((double)(windowWidth / 8), (double)(windowHeight / 8));
                transistorsInfo.AddExit();
            }
            if (other.isCursorPointInButton())
            {
                OtherInfo otherInfo;
                otherInfo.CreateScreen();
                otherInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                otherInfo.AddExit();
            }
            if (exit.isCursorPointInButton())
            {
                ok = 0;
                closegraph(CURRENT_WINDOW);
            }
        }
        delay(200);
    }
}

void InfoMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth, screenHeight, "", -3, -3);

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    capacitors.setPositionCenter(helper.makeVector_2D(windowWidth / 4, windowHeight / 2 - BUTTON_HEIGHT * 4));
    capacitors.setWidth(210);
    capacitors.setHeight(BUTTON_HEIGHT);
    capacitors.setTitle("Capacitors");
    capacitors.Show();

    diodes.setPositionCenter(helper.makeVector_2D(windowWidth / 4, windowHeight / 2 - BUTTON_HEIGHT * 2));
    diodes.setWidth(210);
    diodes.setHeight(BUTTON_HEIGHT);
    diodes.setTitle("Diodes");
    diodes.Show();

    logicGates.setPositionCenter(helper.makeVector_2D(windowWidth / 4, windowHeight / 2));
    logicGates.setWidth(210);
    logicGates.setHeight(BUTTON_HEIGHT);
    logicGates.setTitle("Logic Gates");
    logicGates.Show();

    measurements.setPositionCenter(helper.makeVector_2D(windowWidth / 4, windowHeight / 2 + BUTTON_HEIGHT * 2));
    measurements.setWidth(210);
    measurements.setHeight(BUTTON_HEIGHT);
    measurements.setTitle("Measurements");
    measurements.Show();

    resistors.setPositionCenter(helper.makeVector_2D(windowWidth / 4, windowHeight / 2 + BUTTON_HEIGHT * 4));
    resistors.setWidth(210);
    resistors.setHeight(BUTTON_HEIGHT);
    resistors.setTitle("Resistors");
    resistors.Show();

    sources.setPositionCenter(helper.makeVector_2D(3 * windowWidth / 4, windowHeight / 2 - BUTTON_HEIGHT * 4));
    sources.setWidth(210);
    sources.setHeight(BUTTON_HEIGHT);
    sources.setTitle("Sources");
    sources.Show();

    switches.setPositionCenter(helper.makeVector_2D(3 * windowWidth / 4, windowHeight / 2 - BUTTON_HEIGHT * 2));
    switches.setWidth(210);
    switches.setHeight(BUTTON_HEIGHT);
    switches.setTitle("Switches");
    switches.Show();

    transistors.setPositionCenter(helper.makeVector_2D(3 * windowWidth / 4, windowHeight / 2));
    transistors.setWidth(210);
    transistors.setHeight(BUTTON_HEIGHT);
    transistors.setTitle("Transistors");
    transistors.Show();

    other.setPositionCenter(helper.makeVector_2D(3 * windowWidth / 4, windowHeight / 2 + BUTTON_HEIGHT * 2));
    other.setWidth(210);
    other.setHeight(BUTTON_HEIGHT);
    other.setTitle("Other");
    other.Show();

    exit.setPositionCenter(helper.makeVector_2D(3 * windowWidth / 4, windowHeight / 2 + BUTTON_HEIGHT * 4));
    exit.setWidth(210);
    exit.setHeight(BUTTON_HEIGHT);
    exit.setTitle("Exit");
    exit.Show();
}
