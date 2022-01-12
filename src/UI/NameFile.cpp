#include "UI/NameFile.h"

NameFile::NameFile()
{

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

    bgiout << "Please insert the complete name of the file that will be " << (mode ? "opened" : "saved") << "." <<std :: endl;
    bgiout << "(Example: 'circuit1')" <<std :: endl;

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
    int letterh = windowHeight / 2 + 15;
    char path[101];
    int ascii_c;
    memset(path, '\0', 101);
    int pos = 0;

    while(ok) {
        ascii_c = getch();
        if (ascii_c == 8) { //backspace
            if (pos > 0) {
                pos--;
                path[pos] = '\0';
            }
            bar(windowWidth / 4, windowHeight / 2, 3 * windowWidth / 4, windowHeight / 2 + 50);
            outtextxy(letterw, letterh, path);
            this->filename = path;
        } else if (ascii_c == 13) { // enter
            ok = 0;
            if (filename.size() == 0) {
                std::cout << "cannot " << (mode ? "open" : "save") << " file without a name";
                ok = 1;
            } else {
                ok = 0;
            }
        } else if (ascii_c == 27) { // escape
            ok = 0;
            code = 0;
        } else {
            path[pos++] = (char)(ascii_c);
            path[pos] = '\0';
            outtextxy(letterw, letterh, path);
            this->filename = path;
        }
        delay(200);
    }

    closegraph(this->window_code);
    return code;
}

void NameFile::setMode(int m) {
    mode = m;
}
