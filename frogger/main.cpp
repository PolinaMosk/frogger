#include <QApplication>

#include "game.h"

extern Game * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(0);
    Game * game = new Game();
    game->show();
    return a.exec();
}
