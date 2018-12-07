#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

class Game: public QObject
{
    Q_OBJECT
private:
    QGraphicsView * context;

public:
    Game();
    QGraphicsView * getContext();
    void start();

private slots:
    void spawnEnemy();
};

#endif // GAME_H
