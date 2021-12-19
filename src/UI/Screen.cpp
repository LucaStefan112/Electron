#include "UI/Screen.h"

Screen::Screen()
{
    //ctor
}

void Screen::CreateScreen() {
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth, screenHeight, "", -3, -3);
    setlinestyle(0, 0, 3);
    settextstyle(3, 0, 1);
}

void Screen::AddExit() {
    Button exit;
    Helper helper;

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(25);
    exit.setTitle("Exit");
    exit.Show();

    int ok = 1;

    while (ok) {
        if (GetAsyncKeyState(VK_LBUTTON) && exit.isCursorPointInButton()) {
            ok = 0;
            closegraph(CURRENT_WINDOW);
        }
        delay(200);
    }
}
