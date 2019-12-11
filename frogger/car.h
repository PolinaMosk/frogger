#ifndef VEHICLES_H
#define VEHICLES_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "vehicle.h"

const int CAR_WIDTH = 173;

class Car : public Vehicle
{
    Q_OBJECT
public:
    Car();
    ~Car() override;
    void setLine(int laneNum,int carNum) override;
    void levelUp() override;
signals:
    void crash();
public slots:
    void move();
private :
    unsigned int level;
    QTimer * timer;
    unsigned int line;
};

#endif // CARS_H
