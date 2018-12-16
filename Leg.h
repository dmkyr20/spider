#ifndef LEG_H
#define LEG_H

#include <Arduino.h>
#include <Multiservo.h>

struct Angle {
    short int hip;
    short int knee;
    short int ankle;
};
const Angle LEG_UP = {1, 60, 70};
const Angle LEG_DOWN = {1, -30, 70};
const Angle LEG_CROUCH = {1, 70, 70};
const Angle LEG_FORWARD = {30, 1, 1};
const Angle LEG_BACK = {-50, 1, 1};
const Angle LEG_STD = {1, 1, 1};

class Leg
{
    public:
        Leg(short int pin_hip, short int pin_knee, short int pin_ankle, short int angle_hip, short int angle_knee, short int angle_ankle, char leg_side);
        Leg();
        void setupStaticAngle(short int angle_hip, short int angle_knee, short int angle_ankle);
        bool setupSide(char leg_side);
        void setupLeg();
        Angle getCurentAngle();
        bool moving(Angle angle);
        Angle getStaticAngle();
        void stand();

    //protected:

    private:
        Multiservo HIP;
        Multiservo KNEE;
        Multiservo ANKLE;
        Angle leg_Angle;
        Angle leg_CurentAngle;
        char side;
};

#endif // LEG_H
