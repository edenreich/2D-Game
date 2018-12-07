#include <QTimer>
#include <QList>
#include <typeinfo>
#include "Bullet.h"
#include "Enemy.h"

#include <QGraphicsScene>

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> items = collidingItems();
    for (int i = 0; i < items.size(); ++i) {
        if (typeid(*(items[i])) == typeid(Enemy)) {
            scene()->removeItem(items[i]);
            scene()->removeItem(this);
            delete items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y()-10);

    if (y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
