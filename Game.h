#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>

class Game
{
private:
    QGraphicsView * context;

public:
    Game();
    QGraphicsView * getContext();
    void start();
};

#endif // GAME_H
