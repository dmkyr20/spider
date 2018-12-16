#include "Spider.h"
#include <Leg.h>
#include <Arduino.h>

Spider::Spider(Leg leftTop, Leg leftCenter, Leg leftBottom, Leg rightTop, Leg rightCenter, Leg rightBottom)
{
    this->leftTop = leftTop;
    this->leftCenter = leftCenter;
    this->leftBottom = leftBottom;

    this->rightTop = rightTop;
    this->rightCenter = rightCenter;
    this->rightBottom = rightBottom;
}

Spider::Spider(SpiderAdapter spiderAdapter)
{
    leftTop = spiderAdapter.leftTop;
    leftCenter = spiderAdapter.leftCenter;
    leftBottom = spiderAdapter.leftBottom;

    rightTop = spiderAdapter.rightTop;
    rightCenter = spiderAdapter.rightCenter;
    rightBottom = spiderAdapter.rightBottom;
}

Spider::Spider() {};

/*void Spider::dance()
{

}*/

void Spider::moving(Mover mover, int del = 10)
{
    leftTop.moving(mover.leftTop);
    delay(del);
    rightTop.moving(mover.rightTop);
    delay(del);
    leftCenter.moving(mover.leftCenter);
    delay(del);
    rightCenter.moving(mover.rightCenter);
    delay(del);
    leftBottom.moving(mover.leftBottom);
    delay(del);
    rightBottom.moving(mover.rightBottom);
}

void Spider::setLegs(Leg leftTop, Leg leftCenter, Leg leftBottom, Leg rightTop, Leg rightCenter, Leg rightBottom)
{
    this->leftTop = leftTop;
    this->leftCenter = leftCenter;
    this->leftBottom = leftBottom;

    this->rightTop = rightTop;
    this->rightCenter = rightCenter;
    this->rightBottom = rightBottom;
}
