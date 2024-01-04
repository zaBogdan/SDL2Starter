#include <SDL2/SDL.h>
#include "../utils/checking.h"

class StickManEntity {
    public:
        StickManEntity();
        ~StickManEntity() = default;

        void update(double time);
        void draw(SDL_Surface* surface);

        private:
            SDL_Surface* mBmpImage;
            SDL_Rect mImageRectPos;
            double mImageX = 0.0;
            double mImageY = 0.0;
            bool sign = true;
};