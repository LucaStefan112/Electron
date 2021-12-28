#include "UI/Screen.h"

Screen::Screen()
{
    //ctor
}

void Screen::CreateScreen() {
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    initwindow(screenWidth/2, screenHeight/2, "", -3, -3);
    setlinestyle(0, 0, 3);
    settextstyle(3, 0, 1);
}

