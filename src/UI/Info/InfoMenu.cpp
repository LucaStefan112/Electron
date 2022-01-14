#include "UI/Info/InfoMenu.h"
#include "Helper.h"

#define BUTTON_HEIGHT 30

//daria
InfoMenu::InfoMenu()
{
    //ctor
}
void InfoMenu::WatchClick()
{
    int ok = 1;
    int screenActive = 1;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (capacitors.isCursorPointInButton())
            {
                screenActive = 0;
                CapacitorsInfo capacitorsInfo;
                capacitorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                screenActive = capacitorsInfo.WatchExit();
            }
            else if (diodes.isCursorPointInButton())
            {
                screenActive = 0;
                DiodesInfo diodesInfo;
                diodesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 9));
                screenActive = diodesInfo.WatchExit();
            }
            else if (logicGates.isCursorPointInButton())
            {
                screenActive = 0;
                LogicGatesInfo logicGatesInfo;
                logicGatesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));

                screenActive = logicGatesInfo.WatchExit();
            }
            else if (measurements.isCursorPointInButton())
            {
                screenActive = 0;
                MeasurementsInfo measurementsInfo;
                measurementsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 2));

                screenActive = measurementsInfo.WatchExit();
            }
            else if (resistors.isCursorPointInButton())
            {
                screenActive = 0;
                ResistorsInfo resistorsInfo;
                resistorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 6));

                screenActive = resistorsInfo.WatchExit();
            }
            else if (sources.isCursorPointInButton())
            {
                screenActive = 0;
                SourcesInfo sourcesInfo;
                sourcesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));

                screenActive = sourcesInfo.WatchExit();
            }
            else if (switches.isCursorPointInButton())
            {
                screenActive = 0;
                SwitchesInfo switchesInfo;
                switchesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));

                screenActive = switchesInfo.WatchExit();
            }
            else if (transistors.isCursorPointInButton())
            {
                screenActive = 0;
                TransistorsInfo transistorsInfo;
                transistorsInfo.Show((double)(windowWidth / 8), (double)(windowHeight / 8));

                screenActive = transistorsInfo.WatchExit();
            }
            else if (other.isCursorPointInButton())
            {
                screenActive = 0;
                OtherInfo otherInfo;
                otherInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));

                screenActive = otherInfo.WatchExit();
            }
            else if (exit.isCursorPointInButton())
            {
                ok = 0;
                screenActive = 0;
            }
            if (screenActive)
            {
                setcurrentwindow(this->window_code);
            }
        }
        delay(200);
    }
    delay(200);
    closegraph(this->window_code);
}

void InfoMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth, screenHeight, "", -3, -3);
    this->window_code = wc;
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
