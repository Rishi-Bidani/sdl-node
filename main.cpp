#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>
// #include "SDL.h"
#include "C:\MY DEVELOPMENT\cpp\sdl-node\src\include\SDL.h"
#include "C:\Users\rishi\AppData\Local\node-gyp\Cache\17.0.1\include\node\node.h"

using v8::Local;
using v8::Object;

// int sdlInit(int width, int height, string title, bool fullscreen)
// {
// 	SDL_Window* window;
// 	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
// 	int error = 1;

// 	if (SDL_Init(SDL_INIT_VIDEO) < 0)
// 	{
// 		printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
// 	}

// 	if (!window)
// 	{
// 		printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
// 		return { error, renderer };
// 	}
// 	if (!renderer)
// 	{
// 		printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
// 		return make_pair(error, *renderer);
// 	}
// 	error = 0;
// 	return make_pair(error, *renderer);
// }

class nodeSDL
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    void init(int width, int height, string title, bool fullscreen)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        }
        if (fullscreen)
        {
            window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
        }
        else
        {
            window = SDL_CreateWindow("SLD test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
};

int main(int argc, char **argv)
{
    const int SCREEN_WIDTH = 720;
    const int SCREEN_HEIGHT = 480;

    // nodeSDL nodesdl;
    // nodesdl.init(SCREEN_WIDTH, SCREEN_HEIGHT, "SDL test", true);

    // bool running = true;
    // while (running)
    // {
    //     SDL_Event event;
    //     while (SDL_PollEvent(&event))
    //     {
    //         switch (event.type)
    //         {
    //         case SDL_QUIT:
    //             running = false;
    //             break;

    //         default:
    //             break;
    //         }
    //     }

    // SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    // SDL_RenderClear(renderer);

    // SDL_RenderPresent(renderer);
    // }

    return 0;
}

// void nodesdlInit(int width, int height, string title, bool fullscreen)
// {
//     nodeSDL nodesdl;
//     nodesdl.init(width, height, title, fullscreen);
// }

// void Init(v8::Local<v8::Object> exports)
// {
//     // nodeSDL nodesdl;
//     // NODE_SET_METHOD(exports, "", reinterpret_cast<v8::FunctionCallback>(nodeSDL));
//     NODE_SET_METHOD(exports, "", reinterpret_cast<v8::FunctionCallback>(nodesdlInit));
// }

void Init(v8::Local<v8::Object> exports)
{
    int a = 1;
    NODE_SET_METHOD(exports, "", reinterpret_cast<v8::FunctionCallback>(a));
}

NODE_MODULE(addon, Init);