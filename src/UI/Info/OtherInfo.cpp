#include "UI/Info/OtherInfo.h"

OtherInfo::OtherInfo(): Screen()
{
    //ctor
}
void OtherInfo::Show(double w, double h) {
        Helper helper;

        exit.setPositionUpLeft(helper.makeVector_2D(0, 0));
        exit.setWidth(75);
        exit.setHeight(25);
        exit.setTitle("Exit");
        exit.Show();

        Buzzer buzzer;
        buzzer.setWidth(w / 2);
        buzzer.setPositionUpLeft(helper.makeVector_2D(w,h));
        outtextxy(2 * w, h, strdup(buzzer.name.c_str()));

        Ground ground;
        ground.setWidth(w / 2);
        ground.setPositionUpLeft(helper.makeVector_2D(w * 4,h));
        outtextxy(5 * w, h, strdup(ground.name.c_str()));

        Inductor inductor;
        inductor.setWidth(w / 2);
        inductor.setPositionUpLeft(helper.makeVector_2D(w,h*2));
        outtextxy(2 * w, 2 * h, strdup(inductor.name.c_str()));

        Lamp lamp;
        lamp.setWidth(w / 2);
        lamp.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 2));
        outtextxy(5 * w, 2 * h, strdup(lamp.name.c_str()));

        Microphone microphone;
        microphone.setWidth(w / 2);
        microphone.setPositionUpLeft(helper.makeVector_2D(w,h*3));
        outtextxy(2 * w, 3 * h, strdup(microphone.name.c_str()));

        Motor motor;
        motor.setWidth(w / 2);
        motor.setPositionUpLeft(helper.makeVector_2D(w * 4,h * 3));
        outtextxy(5 * w, 3 * h, strdup(motor.name.c_str()));

        Speaker speaker;
        speaker.setWidth(w / 2);
        speaker.setPositionUpLeft(helper.makeVector_2D(5 * w / 2,h*4));
        outtextxy(7 * w / 2, 4 * h, strdup(speaker.name.c_str()));
}
