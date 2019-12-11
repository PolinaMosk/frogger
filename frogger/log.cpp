#include "log.h"

Log::Log(QObject * parent)
{
    this->setPixmap(QPixmap(":/images/log.png"));
    isHoldingFrog = false;
    level = 1;
}

Log::~Log()
{
    delete timer;
}

void Log::setLine(int laneNum, int logNum)
{
    line = laneNum - 4;
    setPos(logNum * WIDTH / 4 - laneNum * 10, HEIGHT - 78 * (laneNum + 1));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(70 - 5 * laneNum);
}

void Log::levelUp()
{
    level++;
    if (level > 5)
    {
    } else {
    timer->stop();
    switch(line)
    {
    case 1:
       timer->start(5 * (6 - level) * ( 4 - line));
        break;
    case 2:
        timer->start(4 * (6 - level) * ( 5 - line));
    case 3:
        timer->start(4 * (6 - level) * ( 5 - line));
    }
    }
}

void Log::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if (colliding_items.size() == 0) isHoldingFrog = false;
    if (pos().x() + LOG_WIDTH > 0)
    {
        setPos(x() - 10, y());
    } else {
    if (isHoldingFrog)
    {
        dynamic_cast<Frog *>(colliding_items[0])->setPos(WIDTH -10 , y());
    }
    setPos(WIDTH - 10, y());
    }

    for (int i = 0; i < colliding_items.size(); ++i)
     {
         if (typeid (*(colliding_items[i])) == typeid (Frog)) {
             isHoldingFrog = true;
             dynamic_cast<Frog *>(colliding_items[i])->setPos(x() + 49, y()); //посередине бревна

         }
    }
}
