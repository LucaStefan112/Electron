#include "UI/NameFile.h"

NameFile::NameFile()
{
    //ctor
}

void NameFile::Show() {
    Helper helper;
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth, screenHeight, "", -3, -3);
    this->window_code = wc;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    int textw = windowWidth / 5;
    int texth = windowHeight / 4;

    bgiout << "Please insert the complete name of the file that will be saved." <<std :: endl;
    bgiout << "(Example: 'circuit1.txt')" <<std :: endl;

    cancel.setPositionUpLeft(helper.makeVector_2D(windowWidth / 5, windowHeight - 85));
    cancel.setWidth(160);
    cancel.setHeight(35);
    cancel.setTitle("Cancel");
    cancel.Show();

    save.setPositionDownRight(helper.makeVector_2D(4 * windowWidth / 5, windowHeight - 50));
    save.setWidth(160);
    save.setHeight(35);
    save.setTitle("Save");
    save.Show();

    outstreamxy(windowWidth / 5, windowHeight / 4);

    bar(windowWidth / 4, windowHeight / 2, 3 * windowWidth / 4, windowHeight / 2 + 50);

    int ok = 1;
}

int NameFile::ListenEvents () {
    int ok = 1;
    int code = 1;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    int letterw = windowWidth / 4 + 50;
    int letterh = windowHeight / 2 + 25;

    while(ok) {
        std :: cout << getch() << std :: endl;
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (save.isCursorPointInButton()) {
                if (filename.length() == 0) {
                    std::cout << "cannot save file without a name";
                } else {
                    ok = 0;
                }
            } else if (cancel.isCursorPointInButton()) {
                code = 0;
                ok = 0;
            }
        }
        delay(500);
    }

    closegraph(this->window_code);
    return code;
}
