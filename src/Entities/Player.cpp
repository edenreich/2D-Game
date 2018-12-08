#include "Player.h"
#include "Bullet.h"

namespace Src {
    namespace Entities {

        Player::Player(Game * game)
        {
            this->game = game;
            setRect(0, 0, 100, 100);
        }

        void Player::keyPressEvent(QKeyEvent * event)
        {
            switch(event->key())
            {
                case Qt::Key_Left: {
                    moveLeft();
                    break;
                }
                case Qt::Key_Right: {
                    moveRight();
                    break;
                }
                case Qt::Key_Space: {
                    fire();
                    break;
                }
            }
        }

        void Player::moveLeft()
        {
            if (x() < 0) return;

            setPos(x()-10, y());
        }

        void Player::moveRight()
        {
            if (x() > game->getContext()->scene()->width() - rect().width()) return;

            setPos(x()+10, y());
        }

        void Player::decreaseHP()
        {
            qDebug() << "decreasing hp..";
        }

        void Player::fire()
        {
            Bullet * bullet = new Bullet();
            bullet->setPos(x(), y());
            game->getContext()->scene()->addItem(bullet);
        }

    }
}
