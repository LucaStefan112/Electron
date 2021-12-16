#include "UI/InfoMenu.h"
#include "Helper.h"

#define BUTTON_HEIGHT 30

InfoMenu::InfoMenu()
{
    //ctor
}
void InfoMenu::WatchClick() {
    int ok = 1;
    while (ok) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if (capacitors.isCursorPointInButton()) {
                std::cout << "capacitors" << std::endl;
            }
            if (diodes.isCursorPointInButton()) {
                std::cout << "diodes" << std::endl;
            }
            if (logicGates.isCursorPointInButton()) {
                std::cout << "logicGates" << std::endl;
            }
            if (measurements.isCursorPointInButton()) {
                std::cout << "measurements" << std::endl;
            }
            if (resistors.isCursorPointInButton()) {
                std::cout << "resistors" << std::endl;
            }
            if (sources.isCursorPointInButton()) {
                std::cout << "sources" << std::endl;
            }
            if (switches.isCursorPointInButton()) {
                std::cout << "switches" << std::endl;
            }
            if (transistors.isCursorPointInButton()) {
                std::cout << "transistors" << std::endl;
            }
            if (other.isCursorPointInButton()) {
                std::cout << "other" << std::endl;
            }
            if (exit.isCursorPointInButton()) {
                std::cout << "exit" << std::endl;
                ok = 0;
                closegraph(CURRENT_WINDOW);
            }
        }
        delay(200);
    }
}

void InfoMenu::Show() {
    Helper helper;

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
    logicGates.setWidth(160);
    logicGates.setHeight(BUTTON_HEIGHT);
    logicGates.setTitle("Logic Gates");
    logicGates.Show();

    measurements.setPositionCenter(helper.makeVector_2D(windowWidth / 4, windowHeight / 2 + BUTTON_HEIGHT * 2));
    measurements.setWidth(160);
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
