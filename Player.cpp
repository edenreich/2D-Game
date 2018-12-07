#include "Player.h"
#include "Bullet.h"

Player::Player()
{
    setRect(0, 0, 100, 100);
}

void Player::join(Game * game)
{
    if (this->game == nullptr) this->game = game;

    double width = (game->getContext()->width() / 2);
    double height = game->getContext()->height() - this->rect().height();

    this->setPos(width, height);
    game->getContext()->scene()->addItem(this);

    setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
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

void Player::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPos(x(), y());
    game->getContext()->scene()->addItem(bullet);
}
