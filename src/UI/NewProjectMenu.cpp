#include "UI/NewProjectMenu.h"

#define BUTTON_HEIGHT 30

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

    this->CreateScreen();

    this->AddExit();
}
