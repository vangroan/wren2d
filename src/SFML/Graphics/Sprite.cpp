
#include "lib/SFML/Graphics/Sprite.hpp"

#include "Sprite.hpp"


void wren2d::createSprite(WrenVM* vm) {
    SpriteRef** sprite_p = (SpriteRef**)wrenSetSlotNewForeign(vm, 0, 0, sizeof(SpriteRef*));
    *sprite_p = new SpriteRef();
    (*sprite_p)->recount = (Ref){freeSprite, 1};
}


void wren2d::releaseSprite(void* data) {
    SpriteRef** sprite_p = (SpriteRef**)data;
    SpriteRef* sprite = *sprite_p
    decRef(&sprite->refcount);
}


void wren2d::freeSprite(Ref* ref) {
    SpriteRef* sprite = container_of(ref, SpriteRef, refcount);
    delete sprite;
}