#include "car.h"

Car::Car()
{
    this->setPixmap(QPixmap(":/images/car11.png"));
    level = 1;
}

Car::~Car()
{
    delete timer;
}

void Car::setLine(int laneNum, int carNum)
{
    line = laneNum;
    setPos(carNum * WIDTH / (4 - laneNum) + (carNum * 80), HEIGHT - (76 * (laneNum + 1) + (laneNum * 5)));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(40 - 3 * line * level);

}

void Car::levelUp()
{
    level++;
    if (level > 5)
    {
    } else {
    timer->stop();
    switch(line)
    {
    case 1:
       timer->start(25 - 3 * level * line);
        break;
    case 2:
        timer->start(35 - 3 * level * line);
        break;
    case 3:
        timer->start(50 - 3 * level * line);
        break;
    }
    }
}
void Car::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if (x() + CAR_WIDTH > 0)
    {
        setPos(x() - 8, y());
    } else {
    setPos(WIDTH - 10, y());
    }
   for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (typeid (*(colliding_items[i])) == typeid (Frog)){
            emit crash();
         }
    }
}

