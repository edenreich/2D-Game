#include <QTimer>
#include "Enemy.h"

#include <QGraphicsScene>

Enemy::Enemy()
{
    int randomNumber = std::rand() % 700;

    setPos(randomNumber, 0);
    setRect(0, 0, 50, 50);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+5);

    if (y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}
