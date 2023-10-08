#include "engine/common.hpp"
#include "engine/sdl_wrap.hpp"
#include "game.hpp"

#ifdef __vita__
#include <psp2/power.h>
#endif

void handleError(const char* error);

const uint32_t FPS = 60;
const uint32_t MAX_FRAMESKIP = 5;
const uint32_t SKIP_TICKS = FPS / 1000;

int main(int argc, char* argv[])
{

#ifdef __vita__
/*
    scePowerSetArmClockFrequency(222); // default: 444
    scePowerSetBusClockFrequency(111); // default: 222
    scePowerSetGpuClockFrequency(111); // default: 222
    scePowerSetGpuXbarClockFrequency(100); // default: 166
*/
#endif

    Game game = Game(SKIP_TICKS, MAX_FRAMESKIP);

    if (game.gfx.initSDL(VITA_SCREEN_WIDTH, VITA_SCREEN_HEIGHT / 2) == false) {
        handleError("Erro ao iniciar SDL2");
        return -1;
    }

    game.reset();
    printf("Inicializando o game...\n");

    do {
        game.loop();

    } while (game.isRunning); // (ctrl.buttons != SCE_CTRL_START || game.isRunning);

    game.gfx.destroy();

    return 0;
}

void handleError(const char* error)
{
    printf("%s: %s\n\n", error, SDL_GetError());
    printf("Encerrando em 5 segundos...");
    delay(5);
}
