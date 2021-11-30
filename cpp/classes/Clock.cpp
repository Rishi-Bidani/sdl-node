//
// Created by rishi on 30-11-2021.
//

#include "SDL.h"
#include <iostream>

class Clock {
public:
    int SCREEN_FPS;
    int SCREEN_TICKS_PER_FRAME;

    void init(int fps) {
        SCREEN_FPS = fps;
        SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
    }

    static Uint32 getTicks() {
        Uint32 time = SDL_GetTicks();
//        std::cout << time;
        return time;
    }
};
