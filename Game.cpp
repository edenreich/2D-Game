#include "Game.h"

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
    context->show();
}
