#ifndef LOG_H
#define LOG_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "car.h"

const int LOG_WIDTH = 155;
class Log : public Vehicle
{
    Q_OBJECT
public:
    Log(QObject * parent = nullptr);
    ~Log() override;
    void setLine(int laneNum,int logNum) override;
    void levelUp() override;
public slots:
    void move();
private:
    unsigned int level;
    unsigned int line;
    QTimer * timer;
    bool isHoldingFrog;
};

#endif // LOG_H
