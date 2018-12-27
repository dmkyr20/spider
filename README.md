# Arduino library - Spider
This library was created for simple Arduino projects with the use of Multiservo shield for controlling at the same time all 18 servos, which are parts of the robot's legs. Supposed, that the robot has 6 legs with 3 degrees of freedom each (meaning, that 3 servos are responsible for each leg's movement).

## Beginning of work 
The library is designed for Multiservo shield and is based on their library. Therefore, it is necessary to download their library before starting the work. The library can be installed as shown below, previously downloading it as an archive.

![Eng](https://github.com/Antrismus/Spider/blob/master/Illustration/Eng.png)

## Library 
The library contains 2 classes - "Legs" for separate control and characteristic of each leg and "Spider" which controls the whole robot's body.

### Leg
```C++
#include <Leg.h>
```
As said, class "Leg" is used for controlling movements of robot's leg. Each leg is composed of 3 motors (hip - upper servo, knee -middle servo, foot - lower servo).

#### Constructor 
1. Empty leg 
2. leg initialization during the creation

```C++
#include <Leg.h>

void setup() {
  Leg a();
  Leg b(15, 16, 17, 90, 130, 115, 'r');
}
```

#### Methods
1.	setupStaticAngle (setting standard angles for the leg)
```C++
#include <Leg.h>

void setup() {
  Leg b(15, 16, 17, 90, 130, 115, 'r');
  b.setupStaticAngle(90, 130, 115);
}
```
2.	setUpside (setting leg's side)
```C++
#include <Leg.h>

void setup() {
  Leg b(15, 16, 17, 90, 130, 115, 'r');
  b.setupSide('l');
}
```
3.	moving (putting the leg in a specific position with the help of Angle structure).
Angle structure is made up of 3 angles (1 angle for each servo).
```C++
#include <Leg.h>

void setup() {
  Leg b(15, 16, 17, 90, 130, 115, 'r');
  // const Angle LEG_UP = {1, 60, 70}; - Стандартная константа
  b.moving(LEG_UP);
  b.moving({1, 60, 70});
}
```
4.	getCurrentAngle (getting back the angle in which leg is at the moment)
```C++
#include <Leg.h>

void setup() {
  Leg b(15, 16, 17, 90, 130, 115, 'r');
  // const Angle LEG_DOWN = {1, -30, 70}; - Стандартная константа
  b.moving(LEG_DOWN);
  Angle a = b.getCurentAngle();
}
```
5.	get StaticAngle (getting back standard leg's angle)
```C++
#include <Leg.h>

void setup() {
  Leg b(15, 16, 17, 90, 130, 115, 'r');
  // const Angle LEG_DOWN = {1, -30, 70}; - Стандартная константа
  b.moving(LEG_DOWN);
  Angle a = b.getStaticAngle();
}
```

### Spider
```C++
#include <Spider.h>
```
The class which connects all 6 spider's legs

#### Constructor 
1. Initialization of object using legs 
2. Using SpiderAdapter structure.
This structure contains legs which then we can redefine into a spider
3. Object's creation 
```C++
#include <Spider.h>

Spider mySpider;
 
void setup() {
  Leg rightTop(15, 16, 17, 90, 130, 115, 'r');
  Leg leftTop(2, 1, 0, 90, 55, 60, 'l'); 
  Leg rightCenter(12, 13, 14, 95, 130, 130, 'r');
  Leg leftCenter(5, 4, 3, 90, 50, 40, 'l');
  Leg rightBottom(6, 7, 8, 90, 130, 90, 'r');
  Leg leftBottom(9, 10, 11, 90, 40, 50, 'l'); 
  mySpider = Spider(leftTop, leftCenter, leftBottom, rightTop, rightCenter, rightBottom);
}
```

Warning: Be careful - during the legs' creation copies of elements are transmitted, not their links. Therefore, you have to make sure that you erase all extra legs' objects if they are already written in the Spider. 

#### Methods
1. setLegs (installing legs)
```C++
#include <Spider.h>

Spider mySpider;
 
void setup() {
  Leg rightTop(15, 16, 17, 90, 130, 115, 'r');
  Leg leftTop(2, 1, 0, 90, 55, 60, 'l'); 
  Leg rightCenter(12, 13, 14, 95, 130, 130, 'r');
  Leg leftCenter(5, 4, 3, 90, 50, 40, 'l');
  Leg rightBottom(6, 7, 8, 90, 130, 90, 'r');
  Leg leftBottom(9, 10, 11, 90, 40, 50, 'l'); 
  mySpider = Spider(leftTop, leftCenter, leftBottom, rightTop, rightCenter, rightBottom);
  mySpider.setLegs(leftTop, leftCenter, leftBottom, rightTop, rightCenter, rightBottom);
}
```
2. moving (takes Mover structure as an argument. This structure keeps inside all angles for each leg)
```C++
#include <Spider.h>

Spider mySpider;
 
void setup() {
  Serial.begin(9600); 
  Leg rightTop(15, 16, 17, 90, 130, 115, 'r');
  Leg leftTop(2, 1, 0, 90, 55, 60, 'l'); 
  Leg rightCenter(12, 13, 14, 95, 130, 130, 'r');
  Leg leftCenter(5, 4, 3, 90, 50, 40, 'l');
  Leg rightBottom(6, 7, 8, 90, 130, 90, 'r');
  Leg leftBottom(9, 10, 11, 90, 40, 50, 'l'); 
  mySpider = Spider(leftTop, leftCenter, leftBottom, rightTop, rightCenter, rightBottom);
}

void crouch(int del = 200) {
  mySpider.moving(MOVE_CROUCH);
  delay(del);
  mySpider.moving(MOVE_STANDUP);
}
```
