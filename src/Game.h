#ifndef GAME_H
#define GAME_H

#include "vendor.h"

namespace Src {

    class Game: public QObject
    {
        Q_OBJECT
    public:
        Game();
        QGraphicsView * getContext();
        void start();

    private:
        QGraphicsView * context;
        QGraphicsItemGroup * enemies;
        void spawnPlayer();

    private slots:
        void restart();
        void over();
        void spawnEnemy();
    };

}

#endif // GAME_H
