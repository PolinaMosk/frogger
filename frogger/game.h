#ifndef GAME_H
#define GAME_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <vector>
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QFont>

#include "frog.h"
#include "log.h"
#include "text.h"

class Game : public QObject , public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent=nullptr);
    void setup();
    void show();
    void endGame();
    void levelUp();
private:
    Text * text;
    Frog * frog;
    QGraphicsScene * scene;
    std::vector<std::vector<Car *> *> * roadLanes;
    std::vector<std::vector<Log *> *> * waterLanes;
};
#endif //GAME_H
