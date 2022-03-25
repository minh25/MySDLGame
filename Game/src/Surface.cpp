#include "Surface.h"
#include <iostream>

Surface::Surface(const char *filePath)
{
    m_Surface = SDL_LoadBMP(filePath);
    if (m_Surface == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
    }
}

Surface::~Surface()
{
    SDL_FreeSurface(m_Surface);
}
