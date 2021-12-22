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
            if (newProject.isCursorPointInButton()) {
                NewProjectMenu newProjectMenu;
                newProjectMenu.Show();
                newProjectMenu.WatchClick();
            }
            if (openProject.isCursorPointInButton()) {
                // open project functionality
                std::cout << "open project ..." << std::endl;
            }
            if (info.isCursorPointInButton()) {
                InfoMenu infoMenu;
                infoMenu.Show();
                infoMenu.WatchClick();
            }
            if (exit.isCursorPointInButton()) {
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

    newProject.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 - BUTTON_HEIGHT * 3));
    newProject.setWidth(210);
    newProject.setHeight(BUTTON_HEIGHT);
    newProject.setTitle("New Project");
    newProject.Show();

    openProject.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 - BUTTON_HEIGHT));
    openProject.setWidth(210);
    openProject.setHeight(BUTTON_HEIGHT);
    openProject.setTitle("Open Project");
    openProject.Show();

    info.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 + BUTTON_HEIGHT));
    info.setWidth(160);
    info.setHeight(BUTTON_HEIGHT);
    info.setTitle("Info");
    info.Show();

    exit.setPositionCenter(helper.makeVector_2D(windowWidth / 2, windowHeight / 2 + BUTTON_HEIGHT * 3));
    exit.setWidth(160);
    exit.setHeight(BUTTON_HEIGHT);
    exit.setTitle("Exit");
    exit.Show();
}
