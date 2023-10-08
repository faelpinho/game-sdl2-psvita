#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <stdbool.h>
#include <stdint.h>
#include <sys/time.h>

class Engine {
public:
    Engine()
    {
        isPaused = false;

        currentTime = 0;
    };

    void init();
    int getTicks();
    void destroy();

    bool isPaused = false;

    // game loop time variables
    uint32_t maxFrameskip, skipTicks, delta, loops, oldTime, nextTick, currentTime;
};

#endif
