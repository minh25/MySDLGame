#include "SDLWrap.h"

#include <iostream>

SDLWrap::SDLWrap(Uint32 flags)
{
    if (SDL_Init(flags) < 0)
    {
        std::cout << SDL_GetError() << std::endl;
    }
}

SDLWrap::~SDLWrap()
{
    SDL_Quit();
}
