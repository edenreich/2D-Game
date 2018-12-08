#include <QApplication>
#include "src/Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Src::Game * game = new Src::Game;

    game->start();

    return a.exec();
}
