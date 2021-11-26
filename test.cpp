#include <iostream>
#include <string>
#include <stdio.h>
// #include "SDL.h"
#include "C:\MY DEVELOPMENT\cpp\sdl-node\src\include\SDL.h"
#include "C:\Users\rishi\AppData\Local\node-gyp\Cache\17.0.1\include\node\node.h"

namespace nodesdl
{
    using v8::Boolean;
    using v8::Context;
    using v8::Exception;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    double width;
    int height;
    std::string stringTitle;
    bool fullscreen;
    SDL_Window *window;
    SDL_Renderer *renderer;

    void setup(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();

        // Check the number of arguments passed.
        if (args.Length() < 4)
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        // Check argument types
        if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsString() || !args[3]->IsBoolean())
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Get the arguments ----------------------
        width = args[0].As<Number>()->Value();
        height = args[1].As<Number>()->Value();

        // Convert the argument to a C string.
        v8::Local<v8::String> title;
        title = args[2].As<v8::String>();
        char *charTitle = new char[8192];
        (*title)->WriteUtf8(isolate, charTitle);
        stringTitle += charTitle;
        delete charTitle;

        fullscreen = args[3].As<Boolean>()->Value();
        // ----------------------------------------

        std::cout << "width: " << width << std::endl;
        std::cout << "height: " << height << std::endl;
        std::cout << "title: " << stringTitle << std::endl;
        std::cout << "fullscreen: " << fullscreen << std::endl;

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        }

        if (fullscreen)
        {
            window = SDL_CreateWindow(stringTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
        }
        else
        {
            window = SDL_CreateWindow(stringTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
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

    SDL_Event event()
    {
        SDL_Event event;
        return event;
    }

    void Initialise(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "init", reinterpret_cast<v8::FunctionCallback>(setup));
        NODE_SET_METHOD(exports, "event", reinterpret_cast<v8::FunctionCallback>(event));
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialise);
}