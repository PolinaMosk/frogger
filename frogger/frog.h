#ifndef FROG_H
#define FROG_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>


const int WIDTH = 900;
const int HEIGHT = 700;
const int FROG_WIDTH = 90;
const int FROG_HEIGHT = 76;

class Frog : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Frog(QGraphicsItem * parent= nullptr);
    void keyPressEvent(QKeyEvent *event) ;
    void move(const int x, const int y);
    void restart();
signals:
    void win();
};
#endif // FROG_H
