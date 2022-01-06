#include "UI/NewProjectMenu.h"

#define BUTTON_HEIGHT 25
#define COMPONENT_SIZE 100

NewProjectMenu::NewProjectMenu()
{
    //ctor
}

void NewProjectMenu::WatchClick()
{
    int ok = 1;

    Helper helper;
    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    int cType = _none;
    isComponentSelected = false;

    while (ok)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            std :: cout << "click " << std :: endl;
            if (save.isCursorPointInButton())
            {

                //nameFileMenu.Show();
                //int code = nameFileMenu.ListenEvents();
                //setcurrentwindow(this->window_code);

                //bgiout << code << " " << nameFileMenu.filename << std :: endl;
                //outstreamxy(windowWidth / 5, windowHeight / 4);

                //bool hasExtension = strchr(nameFileMenu.filename.c_str(), '.');

                //if (code)
                //{
                //    completeSnapshots.saveToFile(hasExtension ? nameFileMenu.filename : (nameFileMenu.filename + ".txt"));
                //}

            }
            else if (capacitors.isCursorPointInButton())
            {
                std::cout << "capacitors" << std::endl;
                CapacitorsInfo capacitorsInfo;
                capacitorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = capacitorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (diodes.isCursorPointInButton())
            {
                std::cout << "diodes" << std::endl;
                DiodesInfo diodesInfo;
                diodesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 9));
                cType = diodesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (logicGates.isCursorPointInButton())
            {
                std::cout << "logic gates" << std::endl;
                LogicGatesInfo logicGatesInfo;
                logicGatesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = logicGatesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (measurements.isCursorPointInButton())
            {
                std::cout << "measurements" << std::endl;
                MeasurementsInfo measurementsInfo;
                measurementsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 2));
                cType = measurementsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (resistors.isCursorPointInButton())
            {
                std::cout << "resistors" << std::endl;
                ResistorsInfo resistorsInfo;
                resistorsInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 6));
                cType = resistorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (sources.isCursorPointInButton())
            {
                std::cout << "sources" << std::endl;
                SourcesInfo sourcesInfo;
                sourcesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 3));
                cType = sourcesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (switches.isCursorPointInButton())
            {
                std::cout << "switches" << std::endl;
                SwitchesInfo switchesInfo;
                switchesInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = switchesInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (transistors.isCursorPointInButton())
            {
                std::cout << "transistors" << std::endl;
                TransistorsInfo transistorsInfo;
                transistorsInfo.Show((double)(windowWidth / 8), (double)(windowHeight / 8));
                cType = transistorsInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (other.isCursorPointInButton())
            {
                std::cout << "other" << std::endl;
                OtherInfo otherInfo;
                otherInfo.Show((double)(windowWidth / 7), (double)(windowHeight / 5));
                cType = otherInfo.WatchClick();

                std ::cout << "ctype " << cType << std ::endl;
            }
            else if (exit.isCursorPointInButton())
            {
                ok = 0;
            }
            else if (cType != _none)
            {
                std ::cout << "i m here " << cType << std ::endl;
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);
                Helper::Vector_2D pos = helper.makeVector_2D(cursorPoint.x, cursorPoint.y);

                bool isNotBounded = (cursorPoint.x - COMPONENT_SIZE/2) < this->rl ||
                                    (cursorPoint.y - COMPONENT_SIZE/2) < this->rt ||
                                    (cursorPoint.x + COMPONENT_SIZE/2) > this->rr ||
                                    (cursorPoint.y + COMPONENT_SIZE/2) > this->rb;
                if (!isNotBounded)
                {
                    components.addComponent(cType);
                    // std::cout << components.getNumberOfComponents() << " " << components.getSelectedComponent()->toString() << std :: endl;

                    if (components.getSelectedComponent())
                    {
                        components.getSelectedComponent()->setWidth(COMPONENT_SIZE);
                        components.getSelectedComponent()->setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                    }
                }

                cType = _none;
            }
            else if (flip_h.isCursorPointInButton() && components.getSelectedComponent())
            {
                //selectedComponent.flipComponent();
                components.getSelectedComponent()->flipComponent();
            }
            else if (flip_v.isCursorPointInButton() && components.getSelectedComponent())
            {
                /* selectedComponent.rotateComponent(180);
                 delay(300);
                 selectedComponent.flipComponent();
                 */
                components.getSelectedComponent()->rotateComponent(components.getSelectedComponent()->getRotationState() + 180);
                delay(300);
                components.getSelectedComponent()->flipComponent();
            }
            else if (rotate_l.isCursorPointInButton() && components.getSelectedComponent())
            {
                components.getSelectedComponent()->rotateComponent(components.getSelectedComponent()->getRotationState() - 15);
            }
            else if (rotate_r.isCursorPointInButton() && components.getSelectedComponent())
            {
                components.getSelectedComponent()->rotateComponent(components.getSelectedComponent()->getRotationState() + 15);
            }
            else if (inc.isCursorPointInButton() && components.getSelectedComponent())
            {
                components.getSelectedComponent()->setWidth(components.getSelectedComponent()->getWidth() + 15);
            }
            else if (dec.isCursorPointInButton() && components.getSelectedComponent())
            {
                components.getSelectedComponent()->setWidth(components.getSelectedComponent()->getWidth() - 15);
            }
            else if (cType == _none)
            {
                //will move the component
                // POINT cursorPoint;
                // GetCursorPos(&cursorPoint);
                // setcurrentwindow(this->window_code);

                // Helper::Vector_2D pos = helper.makeVector_2D(cursorPoint.x, cursorPoint.y);

                // std :: cout << pos.x << " " << pos.y << std :: endl;
            }


        }
        delay(500);
    }
    closegraph(this->window_code);
}

void NewProjectMenu::Show()
{
    Helper helper;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int wc = initwindow(screenWidth, screenHeight, "", -3, -3);
    this->window_code = wc;

    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();
    double BUTTON_WIDTH = (windowWidth - 50) / 10;

    this->rl = BUTTON_WIDTH * 2,  this->rt = BUTTON_HEIGHT * 3,
          this->rr = windowWidth - BUTTON_WIDTH * 2, this->rb = windowHeight - 3 * BUTTON_HEIGHT;

    rectangle(this->rl, this->rt, this->rr, this->rb);

    exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
    exit.setWidth(75);
    exit.setHeight(BUTTON_HEIGHT);
    exit.setTitle("Exit");
    exit.Show();

    save.setPositionUpLeft(helper.makeVector_2D(75, 0));
    save.setWidth(BUTTON_WIDTH);
    save.setHeight(BUTTON_HEIGHT);
    save.setTitle("Save");
    save.Show();

    capacitors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH + 75, 0));
    capacitors.setWidth(BUTTON_WIDTH);
    capacitors.setHeight(BUTTON_HEIGHT);
    capacitors.setTitle("Capacitors");
    capacitors.Show();

    diodes.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 2 + 75, 0));
    diodes.setWidth(BUTTON_WIDTH);
    diodes.setHeight(BUTTON_HEIGHT);
    diodes.setTitle("Diodes");
    diodes.Show();

    logicGates.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 3 + 75, 0));
    logicGates.setWidth(BUTTON_WIDTH);
    logicGates.setHeight(BUTTON_HEIGHT);
    logicGates.setTitle("Logic Gates");
    logicGates.Show();

    measurements.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 4 + 75, 0));
    measurements.setWidth(BUTTON_WIDTH);
    measurements.setHeight(BUTTON_HEIGHT);
    measurements.setTitle("Measurements");
    measurements.Show();

    resistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 5 + 75, 0));
    resistors.setWidth(BUTTON_WIDTH);
    resistors.setHeight(BUTTON_HEIGHT);
    resistors.setTitle("Resistors");
    resistors.Show();

    sources.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 6 + 75, 0));
    sources.setWidth(BUTTON_WIDTH);
    sources.setHeight(BUTTON_HEIGHT);
    sources.setTitle("Sources");
    sources.Show();

    switches.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 7 + 75, 0));
    switches.setWidth(BUTTON_WIDTH);
    switches.setHeight(BUTTON_HEIGHT);
    switches.setTitle("Switches");
    switches.Show();

    transistors.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 8 + 75, 0));
    transistors.setWidth(BUTTON_WIDTH);
    transistors.setHeight(BUTTON_HEIGHT);
    transistors.setTitle("Transistors");
    transistors.Show();

    other.setPositionUpLeft(helper.makeVector_2D(BUTTON_WIDTH * 9 + 75, 0));
    other.setWidth(BUTTON_WIDTH);
    other.setHeight(BUTTON_HEIGHT);
    other.setTitle("Other");
    other.Show();

    double r = 25;

    rotate_l.setPositionCenter(helper.makeVector_2D(this->rr + 3*r, this->rb - 5*r));
    rotate_l.setWidth(r);
    rotate_l.setHeight(r);
    rotate_l.setTitle("R<-");
    rotate_l.ShowCircleMode();

    rotate_r.setPositionCenter(helper.makeVector_2D(this->rr + 6*r, this->rb - 5*r));
    rotate_r.setWidth(r);
    rotate_r.setHeight(r);
    rotate_r.setTitle("R->");
    rotate_r.ShowCircleMode();

    flip_h.setPositionCenter(helper.makeVector_2D(this->rr + 3*r, this->rb - r));
    flip_h.setWidth(r);
    flip_h.setHeight(r);
    flip_h.setTitle("F<|>");
    flip_h.ShowCircleMode();

    flip_v.setPositionCenter(helper.makeVector_2D(this->rr + 6*r, this->rb -r));
    flip_v.setWidth(r);
    flip_v.setHeight(r);
    flip_v.setTitle("F<->");
    flip_v.ShowCircleMode();

    inc.setPositionCenter(helper.makeVector_2D(this->rl - 3*r, this->rb - 5*r));
    inc.setWidth(r);
    inc.setHeight(r);
    inc.setTitle("+");
    inc.ShowCircleMode();

    dec.setPositionCenter(helper.makeVector_2D(this->rl - 6*r, this->rb - 5*r));
    dec.setWidth(r);
    dec.setHeight(r);
    dec.setTitle("-");
    dec.ShowCircleMode();
}
