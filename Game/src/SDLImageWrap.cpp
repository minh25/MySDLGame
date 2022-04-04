#include "SDLImageWrap.h"

#include <iostream>

SDLImageWrap::SDLImageWrap(int flags)
{
    if (!(IMG_Init(flags) & flags))
    {
        std::cout << IMG_GetError() << std::endl;
    }
}

SDLImageWrap::~SDLImageWrap()
{
    IMG_Quit();
}
