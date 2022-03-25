#include "Window.h"
#include <iostream>

Window::Window(const char *title, int x, int y, int w, int h, Uint32 flags)
{
	m_Window = SDL_CreateWindow(title, x, y, w, h, flags);
	if (m_Window == nullptr)
		std::cout << SDL_GetError() << std::endl;
}

Window::~Window()
{
	SDL_DestroyWindow(m_Window);
}
