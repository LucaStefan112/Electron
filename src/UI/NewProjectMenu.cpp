#include "UI/NewProjectMenu.h"

#define BUTTON_HEIGHT 25

NewProjectMenu::NewProjectMenu(): Screen()
{
    //ctor
}

void NewProjectMenu::WatchClick()
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

void NewProjectMenu::Show()
{
    Helper helper;

    int windowWidth = getwindowwidth();
    double BUTTON_WIDTH = (windowWidth - 75) / 10;

    this->CreateScreen();

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

    this->AddExit();
}
