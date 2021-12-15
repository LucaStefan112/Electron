#include "UI/MainMenu.h"
#include "Helper.h"

#define BUTTON_HEIGHT 30

MainMenu::MainMenu()
{
}

void MainMenu::WatchClick() {
    int ok = 1;
    while (ok) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if (NewProject.isCursorPointInButton()) {
                // create new project functionality
                std::cout << "create new project ..." << std::endl;
            }
            if (OpenProject.isCursorPointInButton()) {
                // open project functionality
                std::cout << "open project ..." << std::endl;
            }
            if (Info.isCursorPointInButton()) {
                std::cout << "info" << std::endl;
            }
            if (Exit.isCursorPointInButton()) {
                std::cout << "exit" << std::endl;
                ok = 0;
                closegraph(CURRENT_WINDOW);
            }
        }
        delay(200);
    }
}

void MainMenu::Show() {
    Helper helper;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    NewProject.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 - BUTTON_HEIGHT * 3));
    NewProject.setWidth(210);
    NewProject.setHeight(BUTTON_HEIGHT);
    NewProject.setTitle("New Project");
    NewProject.Show();

    OpenProject.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 - BUTTON_HEIGHT));
    OpenProject.setWidth(210);
    OpenProject.setHeight(BUTTON_HEIGHT);
    OpenProject.setTitle("Open Project");
    OpenProject.Show();

    Info.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 + BUTTON_HEIGHT));
    Info.setWidth(160);
    Info.setHeight(BUTTON_HEIGHT);
    Info.setTitle("Info");
    Info.Show();

    Exit.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 + BUTTON_HEIGHT * 3));
    Exit.setWidth(160);
    Exit.setHeight(BUTTON_HEIGHT);
    Exit.setTitle("Exit");
    Exit.Show();
}
