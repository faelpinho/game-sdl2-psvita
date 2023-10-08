#include "common/debugScreen.h"
#include "engine/common.hpp"
#include "engine/sdl_wrap.hpp"
#include "game.hpp"

void handleError(const char* error);

// Controle de fps
const uint32_t FPS = 60;
const uint32_t MAX_FRAMESKIP = 5;
const uint32_t SKIP_TICKS = FPS / 1000;

int main(int argc, char* argv[])
{
    Game game = Game(SKIP_TICKS, MAX_FRAMESKIP);

    if (game.gfx.initSDL(VITA_SCREEN_WIDTH, VITA_SCREEN_HEIGHT) == false) {
        handleError("Erro ao iniciar SDL2");
        return -1;
    }

    game.reset();

    do {

        game.loop();

    } while (game.isRunning); // (ctrl.buttons != SCE_CTRL_START || game.isRunning);

    game.gfx.destroy();

    return 0;
}

void handleError(const char* error)
{
    psvDebugScreenInit();
    printf("%s: %s\n\n", error, SDL_GetError());
    printf("Encerrando em 5 segundos...");
    delay(5);
}
