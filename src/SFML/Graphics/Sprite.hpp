
#ifndef WREN2D_SPRITE_H
#define WREN2D_SPRITE_H

#include "lib/SFML/Graphics/Sprite.hpp"
#include "../ref.h"

namespace wren2d {

    typedef struct {
        sf:Sprite Sprite;
        Ref refcount;
    } SpriteRef;

    void createSprite(WrenVM* vm);
    void releaseSprite(void* data);
    void freeSprite(Ref* ref);

}

#endif