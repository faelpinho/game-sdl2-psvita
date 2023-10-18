#include "engine/common.hpp"
#include "engine/graphics.hpp"
#include "game.hpp"
#include <chrono>
#include <thread>
#ifdef __vita__
#include <psp2/power.h>
#endif

void handleError(const char* error);

const uint32_t TICKS_PER_SECOND = 25;
const uint32_t MAX_FRAMESKIP = 5;
const uint32_t SKIP_TICKS = TICKS_PER_SECOND / 1000;

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

    Game game = Game();

    if (game.gfx.init(VITA_SCREEN_WIDTH, VITA_SCREEN_HEIGHT) == false) {
        handleError("Erro ao iniciar SDL2");
        return -1;
    }
    float frameStart, frameEnd;
    float frameDuration;

    game.reset();
    printf("Inicializando o game...\n");

    int loops = 0;
    unsigned long next_game_tick, old_time, current_time, delta;

    do {
        loops = 0;
        while (SDL_GetTicks() > next_game_tick && loops < MAX_FRAMESKIP) {
            game.handleInputs();

            game.handleLogic();

            // old_time = current_time;
            // current_time = SDL_GetTicks();
            // delta = (current_time - old_time) / 1000;

            next_game_tick += SKIP_TICKS;
            loops++;
        }

        game.gfx.clearScreen();
        game.handleGraphics();
        game.gfx.render();

        SDL_Delay(SKIP_TICKS);

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
