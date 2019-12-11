#include "frog.h"
#include "log.h"

Frog::Frog(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    setPos(WIDTH / 2 - FROG_WIDTH / 2 + 5, HEIGHT - FROG_HEIGHT + 5);
    this->setPixmap(QPixmap(":/images/xxsFrog2.png"));
    setScale(0.75);
}

void Frog::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        move(-FROG_WIDTH, 0);
    } else if (event->key() == Qt::Key_Right)
    {
        move(FROG_WIDTH, 0);
    } else if (event->key() == Qt::Key_Up)
    {
        move(0, -FROG_HEIGHT - 2);
    } else if (event->key() == Qt::Key_Down)
    {
        move(0, FROG_HEIGHT + 2);
    }
}
void Frog::move(const int x, const int y)
{
    if (pos().x() + x > WIDTH || pos().x() + x < 0 || y + pos().y() > HEIGHT)
    {
    } else if (pos().y()< 0 )
    {
        emit win();
        restart();
    }
    else {
      setPos(pos().x() + x,pos().y() + y);
    }
    if ((pos().y() < 304) && (pos().y() > /*76*/90))
    {
        QList<QGraphicsItem*> colliding_items = collidingItems();
        if (colliding_items.size() == 0)
        {
            restart();
        }

    }
}

void Frog::restart()
{
    setPos(WIDTH / 2 - FROG_WIDTH / 2 + 5, HEIGHT - FROG_HEIGHT + 5);
}
