#include <QApplication>
#include "Game.h"
#include "Player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game * game = new Game;
    Player * player = new Player;

    player->join(game);
    game->start();

    return a.exec();
}
