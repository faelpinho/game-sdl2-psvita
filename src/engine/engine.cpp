#include "engine.hpp"
#include "sdl_wrap.hpp"
#include <stdbool.h>
#include <stdint.h>

void Engine::init()
{
    //
}

int Engine::getTicks()
{
    // Para facilitar em caso de certas mudanças...
    return SDL_GetTicks();
}

void Engine::destroy()
{
    //
}
