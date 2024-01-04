#include <iostream>
#include <SDL2/SDL.h>

#include "game/core/Application.h"

int main()
{
  std::string appTitle = "Stickman ";
  appTitle += APPLICATION_VERSION;
  Application* app = new Application(1080, 720, appTitle.c_str()); 

  app->loop();

  delete app;
  return EXIT_SUCCESS;
}