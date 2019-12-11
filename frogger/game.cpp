#include "game.h"
#include <QDebug>
Game::Game(QWidget * parent)
{}

void Game::setup()
{
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,WIDTH,HEIGHT); // make the scene 800x600 instead of infinity by infinity (default)
        setFixedSize(900,700);
        scene->setBackgroundBrush(QBrush(QImage(":/images/backgroung.png")));
        text = new Text;
        text->setPos(WIDTH / 3 + 80,0);
        scene->addItem(text);
        QGraphicsView * view = new QGraphicsView(scene);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->show();
}

void Game::levelUp()
{
   text->changeAndShow();
}
void Game::endGame()
{
    frog->restart();
}

void Game::show()
{
    setup();
    frog = new Frog();
    QObject::connect(frog, &Frog::win, this, &Game::levelUp);
    roadLanes = new std::vector<std::vector<Car *>*>;
    waterLanes = new std::vector<std::vector<Log *>*>;

    for (size_t i = 1; i <= 3; i++)
    {
        std::vector<Car *> * cars = new std::vector<Car *>;
        std::vector<Log *> * logs = new std::vector<Log *>;
        for (size_t j = 3; j >= i; j--)
        {
          Car * car = new Car();
          QObject::connect(car, &Car::crash,this,&Game::endGame);
          QObject::connect(frog, &Frog::win,car,&Car::levelUp);
          car->setLine(i, 4 - j);
          cars->push_back(car);
          scene->addItem(car);
        }
        roadLanes->push_back(cars);
        for (size_t k = 1; k < 4; k++)
        {
            Log * log = new Log();
            QObject::connect(frog, &Frog::win, log, &Log::levelUp);
            log->setLine(i + 4, k);
            logs->push_back(log);
            scene->addItem(log);
        }
        waterLanes->push_back(logs);
    }
        frog->setFlag(QGraphicsItem::ItemIsFocusable);
        frog->setFocus();
        scene->addItem(frog);

}
