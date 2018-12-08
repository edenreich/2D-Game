#include "Game.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"

namespace Src {

    Game::Game()
    {
        context = new QGraphicsView(new QGraphicsScene);
        context->setFixedSize(800, 600);
        context->scene()->setSceneRect(0, 0, 800, 600);
        context->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        context->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }

    QGraphicsView * Game::getContext()
    {
        return context;
    }

    void Game::start()
    {
        spawnPlayer();

        QTimer * timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
        timer->start(5000);

        context->show();
    }

    void Game::spawnEnemy()
    {
        qDebug() << "Enemy spawned!";
        Entities::Enemy * enemy = new Entities::Enemy(this);
        context->scene()->addItem(enemy);
        // @todo add the enemy to the group

        QTimer * timer = new QTimer();
        QObject::connect(timer, SIGNAL(timeout()), enemy, SLOT(move()));
        timer->start(50);
    }

    void Game::spawnPlayer()
    {
        Entities::Player * player = new Entities::Player(this);
        double width = (context->width() / 2);
        double height = context->height() - player->rect().height();

        player->setPos(width, height);
        context->scene()->addItem(player);

        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
    }

    void Game::restart()
    {
        context->scene()->destroyItemGroup(enemies);
    }

    void Game::over()
    {
       //
    }
}
