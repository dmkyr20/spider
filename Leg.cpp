#include "Leg.h"
#include <Arduino.h>
#include <Multiservo.h>

Leg::Leg(short int pin_hip, short int pin_knee, short int pin_ankle, short int angle_hip, short int angle_knee, short int angle_ankle, char leg_side)
{
    leg_Angle = {angle_hip, angle_knee, angle_ankle};
    if(leg_side == 'l' || leg_side == 'r') {
        side = leg_side;
    }

    HIP.attach(pin_hip);
    KNEE.attach(pin_knee);
    ANKLE.attach(pin_ankle);
    setupLeg();
}

Leg::Leg() {

}

Angle Leg::getStaticAngle() {
    return leg_Angle;
}

void Leg::stand() {
    moving({1, 1, 1});
}

void Leg::setupStaticAngle(short int angle_hip, short int angle_knee, short int angle_ankle)
{
    leg_Angle = {angle_hip, angle_knee, angle_ankle};
}

bool Leg::setupSide(char leg_side)
{
    if(leg_side == 'l' || leg_side == 'r') {
        side = leg_side;
        return true;
    }
    else {
        return false;
    }
}

void Leg::setupLeg()
{
    HIP.write(leg_Angle.hip);
    KNEE.write(leg_Angle.knee);
    ANKLE.write(leg_Angle.ankle);

    leg_CurentAngle = {leg_Angle.hip, leg_Angle.knee, leg_Angle.ankle};
}

Angle Leg::getCurentAngle()
{
    return leg_CurentAngle;
}

bool Leg::moving(Angle angle)
{
    if(side == 'l') {
        HIP.write(leg_Angle.hip + angle.hip);
        leg_CurentAngle.hip = leg_Angle.hip + angle.hip;
        KNEE.write(leg_Angle.knee + angle.knee);
        leg_CurentAngle.knee = leg_Angle.knee + angle.knee;
        ANKLE.write(leg_Angle.ankle + angle.ankle);
        leg_CurentAngle.ankle = leg_Angle.ankle + angle.ankle;
    }
    else if (side == 'r') {
        HIP.write(leg_Angle.hip - angle.hip);
        leg_CurentAngle.hip = leg_Angle.hip - angle.hip;
        KNEE.write(leg_Angle.knee - angle.knee);
        leg_CurentAngle.knee = leg_Angle.knee - angle.knee;
        ANKLE.write(leg_Angle.ankle - angle.ankle);
        leg_CurentAngle.ankle = leg_Angle.ankle - angle.ankle;
    }
    else {
        return false;
    }
    return true;
}


