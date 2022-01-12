#include "UI/NewProjectMenu.h"
#include "Data Structures/Snapshot.h"

#define BUTTON_HEIGHT 25
#define COMPONENT_SIZE 100
#define BORDER_SPACE 10

Helper NewProjectMenu_helper;

NewProjectMenu::NewProjectMenu()
{
}

void NewProjectMenu::drawWiresForComponent(std::string thisComponentCode, bool eraseMode = false)
{

    ElectronicComponent *currentComponent = currentSnapshot.getComponent(thisComponentCode);

    if (!currentComponent)
        return;

    auto colorMode = (eraseMode) ? BLACK : WHITE;

    if(currentComponent->name == "Connection Node"){

        ElectronicComponent** components = currentSnapshot.getComponents();

        for(int i = 0; i < currentSnapshot.getComponentsNumber(); i++){
            if(components[i])
                for(int j = 0; j < components[i]->getNumberOfConnectionPoints(); j++)
                    if(components[i]->getConnectionPoints()[j].connectedComponentCode == currentComponent->getComponentCode()){
                        NewProjectMenu_helper.drawWire(
                            currentComponent->getPositionCenter(),
                            components[i]->getConnectionPoints()[j].position,
                            colorMode);
                    }
        }
    }

    for (int i = 0; i < currentComponent->getNumberOfConnectionPoints(); i++){

        if (currentComponent->name != "Connection Node" && currentComponent->getConnectionPoints()[i].connectedComponentCode != "cursor" && currentComponent->getConnectionPoints()[i].connectedComponentCode != "-2")
        {

            std::string connectedComponentCode = currentComponent->getConnectionPoints()[i].connectedComponentCode;
            int connectedIndex = currentComponent->getConnectionPoints()[i].connectedIndex;

            NewProjectMenu_helper.drawWire(
                currentComponent->getConnectionPoints()[i].position,
                currentSnapshot.getComponent(connectedComponentCode)->getConnectionPoints()[connectedIndex].position,
                colorMode);
        }
        else if (currentComponent->getConnectionPoints()[i].connectedComponentCode == "cursor")
        {
            POINT cursorPoint;
            GetCursorPos(&cursorPoint);
            setcurrentwindow(this->window_code);

            Helper::Vector_2D point = currentComponent->getConnectionPoints()[i].position;
            Helper::Vector_2D lastCursor = NewProjectMenu_helper.makeVector_2D(lastCursorX, lastCursorY);

            if (lastCursorX != -1)
                NewProjectMenu_helper.drawWire(point, lastCursor, BLACK);
            lastCursorX = cursorPoint.x, lastCursorY = cursorPoint.y;

            delay(1);

            Helper::Vector_2D cursor = NewProjectMenu_helper.makeVector_2D(cursorPoint.x, cursorPoint.y);
            NewProjectMenu_helper.drawWire(point, cursor, WHITE);
        }
    }
}

void NewProjectMenu::refreshScreen(){
    //Clearing the background:
    setfillstyle(SOLID_FILL, BLACK);
    bar(this->rl + 2, this->rt + 2, this->rr, this->rb);
    setfillstyle(SOLID_FILL, WHITE);

    for(int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
            if(currentSnapshot.getComponents()[i]){
                drawWiresForComponent(currentSnapshot.getComponents()[i]->getComponentCode());
                currentSnapshot.getComponents()[i]->Show();
            }

    if(currentSnapshot.getSelectedComponent())  currentSnapshot.getSelectedComponent()->Show();
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
        if (wiring)
            if (currentSnapshot.getSelectedComponent())
            {
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);
                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }

        if (GetAsyncKeyState(VK_LBUTTON) && !GetAsyncKeyState(VK_LCONTROL))
        {
            inc_v1.Hide();
            v1.Hide();
            dec_v1.Hide();
            inc_v2.Hide();
            dec_v2.Hide();
            v2.Hide();
            box.Hide();

            if (save.isCursorPointInButton())
            {
                //currentSnapshot.saveToFile("text.xml");

                nameFileMenu.Show();
                int code = nameFileMenu.ListenEvents();
                setcurrentwindow(this->window_code);

                bgiout << code << " " << nameFileMenu.filename << std ::endl;
                outstreamxy(windowWidth / 5, windowHeight / 4);

                if (code)
                {
                    currentSnapshot.saveToFile(nameFileMenu.filename + ".elc");
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
                for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++) {
                    currentSnapshot.getComponents()[i]->Erase();
                }currentSnapshot.reset();
                ok = 0;
            }
            else if (cType != _none)
            {
                std ::cout << "i m here " << cType << std ::endl;
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                bool isNotBounded = (cursorPoint.x - COMPONENT_SIZE / 2) < this->rl ||
                                    (cursorPoint.y - COMPONENT_SIZE / 2) < this->rt ||
                                    (cursorPoint.x + COMPONENT_SIZE / 2) > this->rr ||
                                    (cursorPoint.y + COMPONENT_SIZE / 2) > this->rb;
                if (!isNotBounded)
                {
                    currentSnapshot.addComponent(cType);

                    if (currentSnapshot.getSelectedComponent())
                    {
                        currentSnapshot.getSelectedComponent()->setWidth(COMPONENT_SIZE);
                        currentSnapshot.getSelectedComponent()->setPositionCenter(helper.makeVector_2D(cursorPoint.x, cursorPoint.y));

                        Change c;
                        c.type = "add";
                        c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                        c.typeOfValue = "component";
                        c.oldValue = "NULL";
                        std::stringstream component;
                        currentSnapshot.saveToStream(component, currentSnapshot.getComponentsNumber() - 1);
                        c.newValue = component.str();
                        changes.clearRedo();
                        changes.addChange(c);
                    }
                }

                cType = _none;
            }

            if (flip_h.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                Change c;
                c.type = "flip";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "bool";
                c.oldValue = currentSnapshot.getSelectedComponent()->flipped ? "true" : "false";

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->flipComponent();

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                c.newValue = currentSnapshot.getSelectedComponent()->flipped ? "true" : "false";
                changes.clearRedo();
                changes.addChange(c);

                refreshScreen();

                delay(300);
            }

            if (flip_v.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                Change c;
                c.type = "flip";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "bool";
                c.oldValue = currentSnapshot.getSelectedComponent()->flipped ? "true" : "false";

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->flipComponent();
                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() + 180);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                c.newValue = currentSnapshot.getSelectedComponent()->flipped ? "true" : "false";
                changes.clearRedo();
                changes.addChange(c);

                refreshScreen();

                delay(300);
            }

            if (rotate_l.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                Change c;
                c.type = "rotate";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "int";
                c.oldValue = std::to_string(currentSnapshot.getSelectedComponent()->rotateState);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() - 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                c.newValue = std::to_string(currentSnapshot.getSelectedComponent()->rotateState);
                changes.clearRedo();
                changes.addChange(c);

                refreshScreen();
            }

            if (rotate_r.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                Change c;
                c.type = "rotate";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "int";
                c.oldValue = std::to_string(currentSnapshot.getSelectedComponent()->rotateState);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->rotateComponent(currentSnapshot.getSelectedComponent()->getRotationState() + 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                c.newValue = std::to_string(currentSnapshot.getSelectedComponent()->rotateState);
                changes.clearRedo();
                changes.addChange(c);

                refreshScreen();
            }

            if (inc.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                Change c;
                c.type = "width";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "double";
                std::stringstream oldValue;
                oldValue << currentSnapshot.getSelectedComponent()->getWidth();
                c.oldValue = oldValue.str();

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->setWidth(currentSnapshot.getSelectedComponent()->getWidth() + 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                std::stringstream newValue;
                newValue << currentSnapshot.getSelectedComponent()->getWidth();
                c.newValue = newValue.str();

                changes.clearRedo();
                changes.addChange(c);

                refreshScreen();
            }

            if (dec.isCursorPointInButton() && currentSnapshot.getSelectedComponent())
            {
                Change c;
                c.type = "width";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "double";
                std::stringstream oldValue;
                oldValue << currentSnapshot.getSelectedComponent()->getWidth();
                c.oldValue = oldValue.str();

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                currentSnapshot.getSelectedComponent()->setWidth(currentSnapshot.getSelectedComponent()->getWidth() - 15);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);

                std::stringstream newValue;
                newValue << currentSnapshot.getSelectedComponent()->getWidth();
                c.newValue = newValue.str();

                changes.clearRedo();
                changes.addChange(c);

                refreshScreen();
            }

            if (undo.isCursorPointInButton() && !changes.undoEmpty())
            {
                implementChangeUndo();
                delay(300);

                refreshScreen();
            }

            if (redo.isCursorPointInButton() && !changes.redoEmpty())
            {
                implementChangeRedo();
                delay(300);

                refreshScreen();
            }

            if (dec_v1.isCursorPointInButton()) {
                Change c;
                c.type = "value";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "string double";
                c.oldValue = currentSnapshot.getSelectedComponent()->getValues()[0].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[0].second);

                currentSnapshot.getSelectedComponent()->setValue(
                    currentSnapshot.getSelectedComponent()->getValues()[0].first,
                    currentSnapshot.getSelectedComponent()->getValues()[0].second - 1);

                c.newValue = currentSnapshot.getSelectedComponent()->getValues()[0].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[0].second);
                changes.clearRedo();
                changes.addChange(c);
            }

            if (inc_v1.isCursorPointInButton()) {
                Change c;
                c.type = "value";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "string double";
                c.oldValue = currentSnapshot.getSelectedComponent()->getValues()[0].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[0].second);

                currentSnapshot.getSelectedComponent()->setValue(
                    currentSnapshot.getSelectedComponent()->getValues()[0].first,
                    currentSnapshot.getSelectedComponent()->getValues()[0].second + 1);

                c.newValue = currentSnapshot.getSelectedComponent()->getValues()[0].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[0].second);
                changes.clearRedo();
                changes.addChange(c);
            }

            if (dec_v2.isCursorPointInButton()) {
                Change c;
                c.type = "value";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "string double";
                c.oldValue = currentSnapshot.getSelectedComponent()->getValues()[1].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[1].second);

                currentSnapshot.getSelectedComponent()->setValue(
                    currentSnapshot.getSelectedComponent()->getValues()[1].first,
                    currentSnapshot.getSelectedComponent()->getValues()[1].second - 1);

                c.newValue = currentSnapshot.getSelectedComponent()->getValues()[1].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[1].second);
                changes.clearRedo();
                changes.addChange(c);
            }

            if (inc_v2.isCursorPointInButton()) {
                Change c;
                c.type = "value";
                c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                c.typeOfValue = "string double";
                c.oldValue = currentSnapshot.getSelectedComponent()->getValues()[1].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[1].second);

                currentSnapshot.getSelectedComponent()->setValue(
                    currentSnapshot.getSelectedComponent()->getValues()[1].first,
                    currentSnapshot.getSelectedComponent()->getValues()[1].second + 1);

                c.newValue = currentSnapshot.getSelectedComponent()->getValues()[1].first + ' ' + std::to_string(currentSnapshot.getSelectedComponent()->getValues()[1].second);
                changes.clearRedo();
                changes.addChange(c);
            }

            //Selecting the component:
            else {
                POINT cursorPoint;
                GetCursorPos(&cursorPoint);
                setcurrentwindow(this->window_code);

                bool cursorOnTable = (this->rl < cursorPoint.x && cursorPoint.x < this->rr && this->rt < cursorPoint.y && cursorPoint.y < this->rb);

                std::cout << cursorPoint.x << ' ' << cursorPoint.y << '\n';

                Helper::Vector_2D cursor = NewProjectMenu_helper.makeVector_2D(cursorPoint.x, cursorPoint.y);

                ElectronicComponent **components = currentSnapshot.getComponents();
                ElectronicComponent *currentComponent = currentSnapshot.getSelectedComponent();
                int isInComponent = -1;

                //Getting the index of the clicked component:
                for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
                    if (components[i])
                        if (components[i]->isCursorPointInButton())
                        {
                            isInComponent = i;
                            break;
                        }

                //Selecting a component:
                if (!wiring && !currentComponent && isInComponent != -1)
                {
                    components[isInComponent]->setOutterBox(true);
                }

                //Selecting another component:
                else if (!wiring && currentComponent && isInComponent != -1)
                {
                    currentComponent->setOutterBox(false);
                    components[isInComponent]->setOutterBox(true);
                }

                //Deselecting a component:
                else if (!wiring && currentComponent && isInComponent == -1 && cursorOnTable)
                {
                    currentComponent->setOutterBox(false);
                }

                //Starting wiring from a connection point of a component:
                if (!wiring && isInComponent != -1){
                    for (int i = 0; i < components[isInComponent]->getNumberOfConnectionPoints(); i++)
                    {
                        Helper::Vector_2D point = components[isInComponent]->getConnectionPoints()[i].position;

                        if (NewProjectMenu_helper.distanceBetween(cursor, point) < components[isInComponent]->getHeight() / 5)
                        {
                            if(components[isInComponent]->getConnectionPoints()[i].connectedComponentCode != "-2"){
                                std::string connectedComponentCode = components[isInComponent]->getConnectionPoints()[i].connectedComponentCode;
                                int connectedComponentIndex = components[isInComponent]->getConnectionPoints()[i].connectedIndex;
                                currentSnapshot.getComponent(connectedComponentCode)->getConnectionPoints()[connectedComponentIndex].connectedComponentCode = "-2";
                            }
                            wiring = true;
                            components[isInComponent]->setConnectedComponentCodeAtPoint(i, "cursor");
                            break;
                        }
                    }
                    refreshScreen();
                    delay(300);
                }

                //Ending wiring for a point by clicking outside any component:
                else if (wiring && isInComponent == -1)
                {
                    for (int i = 0; i < currentComponent->getNumberOfConnectionPoints(); i++)
                        if (currentComponent->getConnectionPoints()[i].connectedComponentCode == "cursor")
                        {
                            wiring = false;
                            currentComponent->getConnectionPoints()[i].connectedComponentCode = "-2";

                            NewProjectMenu_helper.drawWire(
                                currentComponent->getConnectionPoints()[i].position,
                                NewProjectMenu_helper.makeVector_2D(lastCursorX, lastCursorY),
                                BLACK);

                            lastCursorX = lastCursorY = -1;
                            break;
                        }
                    delay(300);
                }

                //Wiring two components:
                else if (wiring && isInComponent != -1)
                {
                    for (int i = 0; i < components[isInComponent]->getNumberOfConnectionPoints(); i++)
                    {
                        Helper::Vector_2D point = components[isInComponent]->getConnectionPoints()[i].position;

                        if (components[isInComponent]->componentCode != currentComponent->componentCode && NewProjectMenu_helper.distanceBetween(cursor, point) < components[isInComponent]->getHeight() / 5 || components[isInComponent]->name == "Connection Node" && NewProjectMenu_helper.distanceBetween(cursor, point) < 20)
                        {
                            wiring = false;

                            int index = 0;

                            while (currentComponent->getConnectionPoints()[index].connectedComponentCode != "cursor")
                                index++;

                            components[isInComponent]->getConnectionPoints()[i].connectedComponentCode = currentComponent->getComponentCode();
                            components[isInComponent]->getConnectionPoints()[i].connectedIndex = index;

                            currentComponent->getConnectionPoints()[index].connectedComponentCode = components[isInComponent]->getComponentCode();
                            currentComponent->getConnectionPoints()[index].connectedIndex = i;

                            break;
                        }
                    }
                    delay(300);
                }

                refreshScreen();
            }
        }

        //Moving the component:
        else if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_LCONTROL))
        {
            inc_v1.Hide();
            v1.Hide();
            dec_v1.Hide();
            inc_v2.Hide();
            dec_v2.Hide();
            v2.Hide();
            box.Hide();

            ElectronicComponent *currentComponent = currentSnapshot.getSelectedComponent();

            if(currentComponent){
                setcurrentwindow(this->window_code);

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode, true);

                POINT cursorPoint;
                GetCursorPos(&cursorPoint);

                double x_point = cursorPoint.x;
                double y_point = cursorPoint.y;

                //keep the component in boundaries
                if (x_point - currentComponent->getWidth() / 2 < this->rl + BORDER_SPACE)
                {
                    x_point = this->rl + BORDER_SPACE + currentComponent->getWidth() / 2;
                }
                else if (x_point + currentComponent->getWidth() / 2 > this->rr - BORDER_SPACE)
                {
                    x_point = this->rr - BORDER_SPACE - currentComponent->getWidth() / 2;
                }

                if (y_point - currentComponent->getHeight() / 2 < this->rt + BORDER_SPACE)
                {
                    y_point = this->rt + BORDER_SPACE + currentComponent->getHeight() / 2;
                }
                else if (y_point + currentComponent->getHeight() / 2 > this->rb - BORDER_SPACE)
                {
                    y_point = this->rb - BORDER_SPACE - currentComponent->getHeight() / 2;
                }

                    currentComponent->setPositionCenter(helper.makeVector_2D(x_point, y_point));

                drawWiresForComponent(currentSnapshot.getSelectedComponent()->componentCode);
            }

            refreshScreen();
        }

        //Deleting the component:
        else if (GetAsyncKeyState(VK_RBUTTON))
        {
            inc_v1.Hide();
            v1.Hide();
            dec_v1.Hide();
            inc_v2.Hide();
            dec_v2.Hide();
            v2.Hide();
            box.Hide();

            auto components = currentSnapshot.getComponents();

            for (int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
                if (components[i]->isCursorPointInButton())
                {
                    Change c;
                    c.type = "delete";
                    c.componentCode = currentSnapshot.getSelectedComponent()->getComponentCode();
                    c.typeOfValue = "component";
                    std::stringstream component;
                    currentSnapshot.saveToStream(component, i);
                    c.oldValue = component.str();
                    c.newValue = "NULL";
                    changes.clearRedo();
                    changes.addChange(c);

                    drawWiresForComponent(components[i]->getComponentCode(), true);
                    currentSnapshot.removeComponent(components[i]->getComponentCode());
                    break;
                }
            refreshScreen();
        }

        else if(GetAsyncKeyState('n') || GetAsyncKeyState('N')){
            inc_v1.Hide();
            v1.Hide();
            dec_v1.Hide();
            inc_v2.Hide();
            dec_v2.Hide();
            v2.Hide();
            box.Hide();

            POINT cursorPoint;
            GetCursorPos(&cursorPoint);

            double x_point = cursorPoint.x;
            double y_point = cursorPoint.y;

            if(this->rl + 4 < x_point && x_point < this->rr - 4 && this->rt + 4 < y_point && y_point < this->rb - 4){

                bool ok = true;

                for(int i = 0; i < currentSnapshot.getComponentsNumber() && ok; i++)
                    if(currentSnapshot.getComponents()[i]->isCursorPointInButton())
                        ok = false;

                if(ok){
                    currentSnapshot.addComponent(100);
                    currentSnapshot.getSelectedComponent()->setPositionCenter(NewProjectMenu_helper.makeVector_2D(x_point, y_point));
                }
            }
            refreshScreen();
            delay(300);
        }


        box.setPositionCenter(helper.makeVector_2D(this->rl - 125, this->rt + 175));
        box.setWidth(150);
        box.setHeight(350);

        if (currentSnapshot.getSelectedComponent()) {
            std::string title = "- Information -\n\n";
            title += "N " + currentSnapshot.getSelectedComponent()->name + '\n';
            title += "C " + currentSnapshot.getSelectedComponent()->getComponentCode() + '\n';
            title += "W " + std::to_string(currentSnapshot.getSelectedComponent()->getWidth()) + '\n';
            title += "H " + std::to_string(currentSnapshot.getSelectedComponent()->getHeight()) + '\n';
            title += "R " + std::to_string(currentSnapshot.getSelectedComponent()->getRotationState()) + '\n';
            title += "F " + std::to_string(currentSnapshot.getSelectedComponent()->flipped) + '\n';
            title += "Xdr " + std::to_string(currentSnapshot.getSelectedComponent()->getPositionDownRight().x) + '\n';
            title += "Ydr " + std::to_string(currentSnapshot.getSelectedComponent()->getPositionDownRight().y) + '\n';
            title += "Xc " + std::to_string(currentSnapshot.getSelectedComponent()->getPositionCenter().x) + '\n';
            title += "Yc " + std::to_string(currentSnapshot.getSelectedComponent()->getPositionCenter().y) + '\n';
            title += "Xul " + std::to_string(currentSnapshot.getSelectedComponent()->getPositionUpLeft().x) + '\n';
            title += "Yul " + std::to_string(currentSnapshot.getSelectedComponent()->getPositionUpLeft().y) + '\n';
            box.setTitle(title);
            box.ShowBox();
        }

        dec_v1.setPositionCenter(helper.makeVector_2D(this->rr + 40, this->rt + 15));
        dec_v1.setWidth(30);
        dec_v1.setHeight(30);
        dec_v1.setTitle("-");
        v1.setPositionCenter(helper.makeVector_2D(this->rr + 150, this->rt + 15));
        v1.setWidth(150);
        v1.setHeight(30);
        inc_v1.setPositionCenter(helper.makeVector_2D(this->rr + 260, this->rt + 15));
        inc_v1.setWidth(30);
        inc_v1.setHeight(30);
        inc_v1.setTitle("+");

        dec_v2.setPositionCenter(helper.makeVector_2D(this->rr + 40, this->rt + 15 + 50));
        dec_v2.setWidth(30);
        dec_v2.setHeight(30);
        dec_v2.setTitle("-");
        v2.setPositionCenter(helper.makeVector_2D(this->rr + 150, this->rt + 15 + 50));
        v2.setWidth(150);
        v2.setHeight(30);
        inc_v2.setPositionCenter(helper.makeVector_2D(this->rr + 260, this->rt + 15 + 50));
        inc_v2.setWidth(30);
        inc_v2.setHeight(30);
        inc_v2.setTitle("+");

        if (currentSnapshot.getSelectedComponent()) {
            auto values = currentSnapshot.getSelectedComponent()->getValues();
            if (values[0].first != "unsupported") {
                if (values.size() == 1) {
                    v1.setTitle(values[0].first + ' ' + std::to_string(values[0].second));
                    dec_v1.Show();
                    v1.Show();
                    inc_v1.Show();
                }else if (values.size() == 2) {
                    v1.setTitle(values[0].first + ' ' + std::to_string(values[0].second));
                    dec_v1.Show();
                    v1.Show();
                    inc_v1.Show();

                    v2.setTitle(values[1].first + ' ' + std::to_string(values[1].second));
                    dec_v2.Show();
                    v2.Show();
                    inc_v2.Show();
                }
            }
        }

        for(int i = 0; i < currentSnapshot.getComponentsNumber(); i++)
            if(currentSnapshot.getComponents()[i]){
                drawWiresForComponent(currentSnapshot.getComponents()[i]->getComponentCode());
                currentSnapshot.getComponents()[i]->Show();
            }

        if(currentSnapshot.getSelectedComponent())  currentSnapshot.getSelectedComponent()->Show();

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

    this->rl = BUTTON_WIDTH * 2, this->rt = BUTTON_HEIGHT * 3,
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

    rotate_l.setPositionCenter(helper.makeVector_2D(this->rr + 3 * r, this->rb - 5 * r));
    rotate_l.setWidth(r);
    rotate_l.setHeight(r);
    rotate_l.setTitle("R<-");
    rotate_l.ShowCircleMode();

    rotate_r.setPositionCenter(helper.makeVector_2D(this->rr + 6 * r, this->rb - 5 * r));
    rotate_r.setWidth(r);
    rotate_r.setHeight(r);
    rotate_r.setTitle("R->");
    rotate_r.ShowCircleMode();

    flip_h.setPositionCenter(helper.makeVector_2D(this->rr + 3 * r, this->rb - r));
    flip_h.setWidth(r);
    flip_h.setHeight(r);
    flip_h.setTitle("F<|>");
    flip_h.ShowCircleMode();

    flip_v.setPositionCenter(helper.makeVector_2D(this->rr + 6 * r, this->rb - r));
    flip_v.setWidth(r);
    flip_v.setHeight(r);
    flip_v.setTitle("F<->");
    flip_v.ShowCircleMode();

    inc.setPositionCenter(helper.makeVector_2D(this->rl - 3 * r, this->rb - 5 * r));
    inc.setWidth(r);
    inc.setHeight(r);
    inc.setTitle("+");
    inc.ShowCircleMode();

    dec.setPositionCenter(helper.makeVector_2D(this->rl - 6 * r, this->rb - 5 * r));
    dec.setWidth(r);
    dec.setHeight(r);
    dec.setTitle("-");
    dec.ShowCircleMode();

    redo.setPositionCenter(helper.makeVector_2D(this->rl - 3*r, this->rb - r));
    redo.setWidth(r);
    redo.setHeight(r);
    redo.setTitle("Redo");
    redo.ShowCircleMode();

    undo.setPositionCenter(helper.makeVector_2D(this->rl - 6*r, this->rb - r));
    undo.setWidth(r);
    undo.setHeight(r);
    undo.setTitle("Undo");
    undo.ShowCircleMode();
}

void NewProjectMenu::implementChangeUndo() {
    auto c = changes.getUndo();

    if (c.type == "add") {
        currentSnapshot.removeComponent(c.componentCode);
    } else if (c.type == "delete") {
        std::stringstream strm(c.oldValue);
        currentSnapshot.importFromStream(strm);
    } else if (c.type == "flip") { // works
        currentSnapshot.getComponent(c.componentCode)->flipComponent();
    } else if (c.type == "rotate") { // works
        currentSnapshot.getComponent(c.componentCode)->rotateComponent(std::stoi(c.oldValue));
    } else if (c.type == "width") { // works
        currentSnapshot.getComponent(c.componentCode)->setWidth(std::stod(c.oldValue));
    } else if (c.type == "value") {
        std::stringstream strm(c.oldValue);
        std::string str;
        double value;
        strm >> str >> value;
        currentSnapshot.getComponent(c.componentCode)->setValue(str, value);
    }
}

void NewProjectMenu::implementChangeRedo() {
    auto c = changes.getRedo();

    if (c.type == "add") {
        std::stringstream strm(c.newValue);
        std::cout << strm.str();
        currentSnapshot.importFromStream(strm);
    } else if (c.type == "delete") {
        currentSnapshot.removeComponent(c.componentCode);
    } else if (c.type == "flip") { // works
        currentSnapshot.getComponent(c.componentCode)->flipComponent();
    } else if (c.type == "rotate") { // works
        currentSnapshot.getComponent(c.componentCode)->rotateComponent(std::stoi(c.newValue));
    } else if (c.type == "width") { // works
        currentSnapshot.getComponent(c.componentCode)->setWidth(std::stod(c.newValue));
    } else if (c.type == "value") {
        std::stringstream strm(c.newValue);
        std::string str;
        double value;
        strm >> str >> value;
        currentSnapshot.getComponent(c.componentCode)->setValue(str, value);
    }
}
