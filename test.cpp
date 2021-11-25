#include <string>
#include <iostream>
#include <stdio.h>
// #include "SDL.h"
#include "C:\MY DEVELOPMENT\cpp\sdl-node\src\include\SDL.h"
#include "C:\Users\rishi\AppData\Local\node-gyp\Cache\17.0.1\include\node\node.h"

namespace nodesdl
{
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    int width;
    int height;
    std::string title;
    bool fullscreen;
    SDL_Window *window;
    SDL_Renderer *renderer;

    void setup(int width, int height, std::string title, bool fullscreen)
    {
        // width = width;
        // height = height;
        // title = title;
        // fullscreen = fullscreen;

        std::cout << width << height;

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
        bool running = true;
        while (running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_QUIT:
                    running = false;
                    break;

                default:
                    break;
                }
            }
        }
    }

    // void Method(const FunctionCallbackInfo<Value> &args)
    // {
    //     Isolate *isolate = args.GetIsolate();

    // }

    void Initialise(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "hello", reinterpret_cast<v8::FunctionCallback>(setup));
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialise);
}