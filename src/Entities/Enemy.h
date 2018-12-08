#ifndef ENEMY_H
#define ENEMY_H

#include "vendor.h"
#include "src/Game.h"

namespace Src {
    namespace Entities {

        class Enemy: public QObject, public QGraphicsRectItem
        {
            Q_OBJECT
        public:
            Enemy(Game * game);

        private:
            Game * game;

        signals:
            void hit();

        public slots:
            void move();
        };

    }
}

#endif // ENEMY_H
