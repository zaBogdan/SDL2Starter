#include <SDL2/SDL.h>
#include "../utils/checking.h"
#include "../entities/stickman.h"

#define APPLICATION_VERSION "0.0.1"

class Application {
    public:
        Application(int width, int height, const char* title);
        ~Application();

        void loop();
        void draw();

    private:
        static Application* instance;
        SDL_Window* mWindow;
        SDL_Surface *mWindowSurface;
        SDL_Event mWindowEvent;

        StickManEntity *mStickMan;
};
