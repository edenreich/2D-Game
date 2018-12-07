#include <QTimer>
#include "Game.h"
#include "Enemy.h"

Game::Game()
{
    context = new QGraphicsView(new QGraphicsScene);
    context->setFixedSize(800, 600);
    context->scene()->setSceneRect(0, 0, 800, 600);
    context->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    context->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    timer->start(5000);
}

QGraphicsView * Game::getContext()
{
    return context;
}

void Game::start()
{
    context->show();
}

void Game::spawnEnemy()
{
    Enemy * enemy = new Enemy();
    getContext()->scene()->addItem(enemy);
}
