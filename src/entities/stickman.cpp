#include "game/entities/stickman.h"

StickManEntity::StickManEntity() {
    mBmpImage = SDL_LoadBMP("./assets/test.bmp");
    CHECKRETNONE(mBmpImage, "SDL_LoadBMP failed with error: %s", SDL_GetError());

    mImageRectPos.x = 0;
    mImageRectPos.y = 0;
    mImageRectPos.w = mBmpImage->w;
    mImageRectPos.h = mBmpImage->h;
}

void StickManEntity::update(double time) {
    if (mImageX > 1080 - mImageRectPos.w)
    {
        sign = !sign;
    }
    if (mImageX < 0)
    {
        sign = !sign;
    }
    
    mImageX = mImageX + (sign ? (5*time) : -(5*time));
    mImageRectPos.x = mImageX;
}

void StickManEntity::draw(SDL_Surface* surface) {
    SDL_BlitSurface(mBmpImage, NULL, surface, &mImageRectPos);
}