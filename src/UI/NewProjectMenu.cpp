#include "UI/NewProjectMenu.h"
#include "Data Structures/Snapshot.h"

#define BUTTON_HEIGHT 25
#define COMPONENT_SIZE 100

Helper NewProjectMenu_helper;

NewProjectMenu::NewProjectMenu()
{

}

void NewProjectMenu::drawWiresForComponent(std::string thisComponentCode, bool eraseMode = false){

    ElectronicComponent** currentComponents = currentSnapshot.getComponents();

    int index = 0;

    auto colorMode = (eraseMode) ? BLACK : WHITE;

    while(currentComponents[index] -> componentCode != thisComponentCode && index < 100)  index++;

    ElectronicComponent* currentComponent = currentComponents[index];

    for(int i = 0; i < currentComponent -> getNumberOfConnectionPoints(); i++){

        if(currentComponent -> getConnectionPoints()[i].connectedIndex != -1){

            std::string connectedComponentCode = currentComponent -> getConnectionPoints()[i].connectedComponentCode;
            int connectedIndex = currentComponent -> getConnectionPoints()[i].connectedIndex;

            NewProjectMenu_helper.drawWire(
                currentComponent -> getConnectionPoints()[i].position,
                currentSnapshot.getComponent(connectedComponentCode) -> getConnectionPoints()[connectedIndex].position,
                colorMode);
        }
        else if(currentComponent -> getConnectionPoints()[i].connectedComponentCode == "cursor"){
            POINT cursorPoint;
            GetCursorPos(&cursorPoint);
            setcurrentwindow(this->window_code);

            Helper::Vector_2D point = currentComponent->getConnectionPoints()[i].position;
            Helper::Vector_2D lastCursor = NewProjectMenu_helper.makeVector_2D(lastCursorX, lastCursorY);

            if(lastCursorX != -1)
                NewProjectMenu_helper.drawWire(point, lastCursor, BLACK);
            lastCursorX = cursorPoint.x, lastCursorY = cursorPoint.y;

            delay(1);

            Helper::Vector_2D cursor = NewProjectMenu_helper.makeVector_2D(cursorPoint.x, cursorPoint.y);
            NewProjectMenu_helper.drawWire(point, cursor, WHITE);
        }
    }

}

void NewProjectMenu::WatchClick()
{
    int ok = 1;

    Helper helper;
    int windowWidth = getwindowwidth();
    int windowHeight = getwindowheight();

    int cType = _none;
    iscurrentSnapshotelected = false;

    while (ok)
    {
        if(wiring)
            if(currentSnapshot.getSelectedComponent()){
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }

        if (GetAsyncKeyState(VK_LBUTTON) && !GetAsyncKeyState(VK_LCONTROL))
        {
            std :: cout << "click " << std :: endl;
            if (save.isCursorPointInButton())
            {
                //currentSnapshot.saveToFile("text.xml");

                nameFileMenu.Show();
                int code = nameFileMenu.ListenEvents();
                setcurrentwindow(this->window_code);

                bgiout << code << " " << nameFileMenu.filename << std :: endl;
                outstreamxy(windowWidth / 5, windowHeight / 4);

                if (code)
                {
                    currentSnapshot.saveToFile(nameFileMenu.filename + ".xml");
                }
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
                currentSnapshot.reset();
                ok = 0;
            }
            else if (cType != _none)
            {
                std ::cout << "i m here " << cType << std ::endl;
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                bool isNotBounded = (cursorPoint.x - COMPONENT_SIZE/2) < this->rl ||
                                    (cursorPoint.y - COMPONENT_SIZE/2) < this->rt ||
                                    (cursorPoint.x + COMPONENT_SIZE/2) > this->rr ||
                                    (cursorPoint.y + COMPONENT_SIZE/2) > this->rb;
                if (!isNotBounded)
                {
                    currentSnapshot.addComponent(cType);

                    if (currentSnapshot.getSelectedComponent())
                    {
                        currentSnapshot.getSelectedComponent()->setWidth(COMPONENT_SIZE);
                        currentSnapshot.getSelectedComponent()->setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                    }
                }

                cType = _none;
            }
            else if (flip_h.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->flipComponent();

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                delay(300);
            }
            else if (flip_v.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->flipComponent();
                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() + 180);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                delay(300);
            }
            else if (rotate_l.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() - 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }
            else if (rotate_r.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() + 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }
            else if (inc.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->setWidth(currentSnapshot.getSelectedComponent()->getWidth() + 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }
            else if (dec.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->setWidth(currentSnapshot.getSelectedComponent()->getWidth() - 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }
            else{
                std::cout << "select\n";

                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                wiring = false;
                auto components = currentSnapshot.getComponents();
                int isInComponent = -1;

                for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
                    if(components[i])
                        if (components[i]->isCursorPointInButton()){
                            isInComponent = i;  break;
                        }

                if(isInComponent == -1 && currentSnapshot.getSelectedComponent()){
                    for(int i = 0; i < currentSnapshot.getSelectedComponent()->getNumberOfConnectionPoints(); i++)
                        if(currentSnapshot.getSelectedComponent()->getConnectionPoints()[i].connectedComponentCode == "cursor"){

                            NewProjectMenu_helper.drawWire(
                                currentSnapshot.getSelectedComponent()->getConnectionPoints()[i].position,
                                NewProjectMenu_helper.makeVector_2D(lastCursorX, lastCursorY),
                                BLACK);

                            currentSnapshot.getSelectedComponent()->getConnectionPoints()[i].connectedComponentCode = "-2";

                            break;
                        }
                    currentSnapshot.getSelectedComponent()->setOutterBox(false);
                }
                else if(isInComponent != -1){
                    if(!currentSnapshot.getSelectedComponent())
                        components[isInComponent]->setOutterBox(true);

                    else if(components[isInComponent]->getComponentCode() == currentSnapshot.getSelectedComponent()->getComponentCode() && wiring){
                        for(int i = 0; i < currentSnapshot.getSelectedComponent()->getNumberOfConnectionPoints(); i++)
                        if(currentSnapshot.getSelectedComponent()->getConnectionPoints()[i].connectedComponentCode == "cursor"){

                            NewProjectMenu_helper.drawWire(
                                currentSnapshot.getSelectedComponent()->getConnectionPoints()[i].position,
                                NewProjectMenu_helper.makeVector_2D(lastCursorX, lastCursorY),
                                BLACK);

                            currentSnapshot.getSelectedComponent()->getConnectionPoints()[i].connectedComponentCode = "-2";

                            break;
                        }
                    }
                    else if(components[isInComponent]->getComponentCode() != currentSnapshot.getSelectedComponent()->getComponentCode() && !wiring){
                        currentSnapshot.getSelectedComponent()->setOutterBox(false);
                        components[isInComponent]->setOutterBox(true);
                    }
                    else{
                        for(int j = 0; j < components[isInComponent]->getNumberOfConnectionPoints(); j++){

                            Helper::Vector_2D point = components[isInComponent]->getConnectionPoints()[j].position;
                            Helper::Vector_2D cursor = NewProjectMenu_helper.makeVector_2D(cursorPoint.x, cursorPoint.y);

                            if(NewProjectMenu_helper.distanceBetween(point, cursor) < components[isInComponent]->getHeight() / 10 && !wiring){
                                components[isInComponent]->setConnectedComponentCodeAtPoint(j, "cursor");

                                wiring = true;
                            }
                            else if(NewProjectMenu_helper.distanceBetween(point, cursor) < components[isInComponent]->getHeight() / 10 && wiring){

                                int aIndex = -1;

                                for(int k = 0; k < currentSnapshot.getSelectedComponent()->getNumberOfConnectionPoints(); k++)
                                    if(currentSnapshot.getSelectedComponent()->getConnectionPoints()[k].connectedComponentCode == "cursor"){
                                        aIndex = k; break;
                                    }

                                components[isInComponent]->setConnectedComponentCodeAtPoint(j, currentSnapshot.getSelectedComponent()->getComponentCode());
                                currentSnapshot.getSelectedComponent()->setConnectedComponentCodeAtPoint(aIndex, components[isInComponent]->getComponentCode());

                                components[isInComponent]->getConnectionPoints()[j].connectedIndex = aIndex;
                                currentSnapshot.getSelectedComponent()->getConnectionPoints()[aIndex].connectedIndex = j;

                                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                                currentSnapshot.getSelectedComponent()->setOutterBox(false);
                                wiring = false;
                            }
                        }
                    }
                }
            }
        }
        else if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_LCONTROL))
        {
            std :: cout << "move component" << std :: endl;

            POINT cursorPoint;
            GetCursorPos(&cursorPoint);
            setcurrentwindow(this->window_code);

            if(currentSnapshot.getSelectedComponent()){
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);
                currentSnapshot.getSelectedComponent()->setPositionCenter(NewProjectMenu_helper.makeVector_2D(cursorPoint.x, cursorPoint.y));
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }
        }
        else if (GetAsyncKeyState(VK_RBUTTON))
        {
            std::cout << "trydelete\n";
            auto components = currentSnapshot.getComponents();

            for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
                if (components[i]->isCursorPointInButton())
                {
                    std::cout << "delete\n";
                    drawWiresForComponent(components[i]->getComponentCode(), true);
                    currentSnapshot.removeComponent(components[i]->getComponentCode());
                    break;
                }

        }
        delay(50);
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
