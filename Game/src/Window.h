#pragma once

#include <SDL.h>

class Window
{
public:
    Window(const char *title, int x, int y, int w, int h, Uint32 flags);
    ~Window();

    inline void Update() { SDL_UpdateWindowSurface(m_Window); }

    inline SDL_Window *Get() { return m_Window; };
    inline SDL_Surface *GetSurface() { return SDL_GetWindowSurface(m_Window); };

private:
    SDL_Window *m_Window;
};