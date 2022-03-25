#pragma once

#include <SDL.h>

class Surface
{
public:
    Surface(const char *filePath);
    ~Surface();

    inline SDL_Surface *Get() { return m_Surface; }

private:
    SDL_Surface *m_Surface;
};