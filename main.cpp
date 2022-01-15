#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <windows.h>

#include "Electronic Components/Electronics.h"
#include "UI/UI.h"
#include "Helper.h"

using namespace std;

Helper helper;

int main()
{
    MainMenu menu;
    menu.Show();
    menu.WatchClick();

    return 0;
}
