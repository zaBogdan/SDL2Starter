#include "game/core/Application.h"

Application *Application::instance = nullptr;

Application::Application(int width, int height, const char* title) {
    if (instance == nullptr) {
        instance = this;
    } else {
        CHECKRETNONE(true, "Application already exists");
    }

    CHECKRETNONE(SDL_Init(SDL_INIT_EVERYTHING) <= 0, "SDL_Init failed with error: %s", SDL_GetError());
    
    mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    CHECKRETNONE(mWindow, "SDL_CreateWindow failed with error: %s", SDL_GetError());

    mWindowSurface = SDL_GetWindowSurface(mWindow);
    CHECKRETNONE(mWindowSurface, "SDL_GetWindowSurface failed with error: %s", SDL_GetError());

    mStickMan = new StickManEntity();
}

void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&mWindowEvent) > 0)
        {
            switch(mWindowEvent.type)
            {
                case SDL_QUIT:
                keep_window_open = false;
                break;
            }
        }
        mStickMan->update(5.0 / 60.0);
        this->draw();
    }
}

void Application::draw() {
    SDL_FillRect(mWindowSurface, NULL, SDL_MapRGB(mWindowSurface->format, 0, 0, 0));
    mStickMan->draw(mWindowSurface);
    SDL_UpdateWindowSurface(mWindow);
}

Application::~Application() {
    SDL_FreeSurface(mWindowSurface);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

