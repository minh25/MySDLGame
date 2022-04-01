#define SDL_MAIN_HANDLED

#include <memory>
#include <iostream>
#include "Window.h"
#include "Surface.h"
#include "SDLWrap.h"

// Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

int main(int argc, char *args[])
{
    std::unique_ptr<SDLWrap> sdlWrap(new SDLWrap(SDL_INIT_VIDEO));

    std::unique_ptr<Window> window(new Window("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN));

    std::unique_ptr<Surface> surface(new Surface("x.bmp"));
    std::shared_ptr<Surface> keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
    std::shared_ptr<Surface> curSurface;
    keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = std::make_shared<Surface>("press.bmp");
    keyPressSurfaces[KEY_PRESS_SURFACE_UP] = std::make_shared<Surface>("up.bmp");
    keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = std::make_shared<Surface>("down.bmp");
    keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = std::make_shared<Surface>("left.bmp");
    keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = std::make_shared<Surface>("right.bmp");

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    curSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

    // While application is running
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    curSurface = keyPressSurfaces[KEY_PRESS_SURFACE_UP];
                    break;

                case SDLK_DOWN:
                    curSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
                    break;

                case SDLK_LEFT:
                    curSurface = keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                    break;

                case SDLK_RIGHT:
                    curSurface = keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                    break;

                default:
                    curSurface = keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                    break;
                }
            }
        }

        // Apply the image
        SDL_BlitSurface(curSurface->Get(), NULL, window->GetSurface(), NULL);

        window->Update();
    }

    return 0;
}