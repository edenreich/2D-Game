#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QKeyEvent>


class Player: public QGraphicsRectItem
{
private:
    Game * game = nullptr;
public:
    Player();
    void join(Game * game);
    void keyPressEvent(QKeyEvent * event);
    void fire();
    void moveLeft();
    void moveRight();
};

#endif // PLAYER_H
