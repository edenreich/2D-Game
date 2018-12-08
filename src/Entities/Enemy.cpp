#include "Enemy.h"
#include "Player.h"

namespace Src {
    namespace Entities {

        Enemy::Enemy(Game * game)
        {
            this->game = game;
            int randomNumber = std::rand() % 700;

            setPos(randomNumber, 0);
            setRect(0, 0, 50, 50);
        }

        void Enemy::move()
        {
            QList<QGraphicsItem *> items = collidingItems();
            for (int i = 0; i < items.size(); ++i) {
                if (typeid(*(items[i])) == typeid(Player)) {
                    qDebug() << "Enemy hit the player";
                    // @todo send a signal to the player and reduce hp
                    delete this;
                    return;
                }
            }

            setPos(x(), y()+5);

            if (y() > game->getContext()->scene()->height()) {
                game->getContext()->scene()->removeItem(this);
                delete this;
            }
        }

    }
}
