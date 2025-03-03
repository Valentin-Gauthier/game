#ifndef TERRAIN_H
#define TERRAIN_H

#include <QPixmap>
using namespace std;

class Terrain{
public:
    Terrain(const QString& texture, int width, int height, int posX, int posY);

    virtual ~Terrain() = default;

    QString texture;
    int width;
    int height;
    int posX;
    int posY;

};

#endif // TERRAIN_H
