#ifndef PLAYER_H
#define PLAYER_H

#include "vendor.h"
#include "src/Game.h"

namespace Src {
    namespace Entities {

        class Player: public QGraphicsRectItem
        {  
        public:
            Player(Game * game);
            void keyPressEvent(QKeyEvent * event);
            void fire();
            void moveLeft();
            void moveRight();

        public slots:
            void decreaseHP();

        private:
            Game * game;
        };

    }
}

#endif // PLAYER_H
