#ifndef SPIDER_H
#define SPIDER_H

#include<Leg.h>

struct Mover {
    Angle leftTop;
    Angle leftCenter;
    Angle leftBottom;
    Angle rightTop;
    Angle rightCenter;
    Angle rightBottom;
};

const Mover MOVE_TURN_LEFT = {LEG_FORWARD, LEG_FORWARD, LEG_FORWARD, LEG_BACK, LEG_BACK, LEG_BACK};
const Mover MOVE_TURN_RIGHT = {LEG_BACK, LEG_BACK, LEG_BACK, LEG_FORWARD, LEG_FORWARD, LEG_FORWARD};
const Mover MOVE_CROUCH = {LEG_CROUCH, LEG_CROUCH, LEG_CROUCH, LEG_CROUCH, LEG_CROUCH, LEG_CROUCH};
const Mover MOVE_STANDUP = {LEG_STD, LEG_STD, LEG_STD, LEG_STD, LEG_STD, LEG_STD};

struct SpiderAdapter {
    Leg leftTop;
    Leg leftCenter;
    Leg leftBottom;
    Leg rightTop;
    Leg rightCenter;
    Leg rightBottom;
};

//const SpiderAdapter STANDART_SPIDER_ADAPTER;

class Spider
{
    public:
        Spider(SpiderAdapter spiderAdapter);
        Spider(
                Leg leftTop,
                Leg leftCenter,
                Leg leftBottom,
                Leg rightTop,
                Leg rightCenter,
                Leg rightBottom    );
        Spider();
        void setLegs(
                Leg leftTop,
                Leg leftCenter,
                Leg leftBottom,
                Leg rightTop,
                Leg rightCenter,
                Leg rightBottom    );
        //void dance();
        void moving(Mover mover, int del = 10);

    private:
        Leg leftTop;
        Leg leftCenter;
        Leg leftBottom;
        Leg rightTop;
        Leg rightCenter;
        Leg rightBottom;
};

#endif // SPIDER_H
