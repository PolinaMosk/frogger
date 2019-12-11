#ifndef VEHICLE_H
#define VEHICLE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>

#include "frog.h"

class Vehicle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    virtual void setLine(int laneNum,int carNum) = 0;
    virtual void levelUp() = 0;
};

#endif // VEHICLE_H
