#ifndef BULLET_H
#define BULLET_H

#include "vendor.h"

namespace Src {
    namespace Entities {

        class Bullet: public QObject, public QGraphicsRectItem
        {
            Q_OBJECT
        public:
            Bullet();

        private slots:
            void move();
        };

    }
}

#endif // BULLET_H
