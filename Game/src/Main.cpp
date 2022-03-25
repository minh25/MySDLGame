#define SDL_MAIN_HANDLED

#include <memory>
#include <iostream>
#include "Window.h"
#include "Surface.h"
#include "SDLWrap.h"

// Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

int main(int argc, char *args[])
{
    std::unique_ptr<SDLWrap> sdlWrap(new SDLWrap(SDL_INIT_VIDEO));

    std::unique_ptr<Window> window(new Window("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN));

    std::unique_ptr<Surface> surface(new Surface("x.bmp"));

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

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
        }

        // Apply the image
        SDL_BlitSurface(surface->Get(), NULL, window->GetSurface(), NULL);

        window->Update();
    }

    return 0;
}