#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
// #include "SDL.h"
#include "C:\MY DEVELOPMENT\cpp\sdl-node\src\include\SDL.h"
#include "C:\Users\rishi\AppData\Local\node-gyp\Cache\17.0.1\include\node\node.h"

namespace nodesdl
{
    using v8::Array;
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
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

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
    }

    auto event(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                args.GetReturnValue().Set(String::NewFromUtf8(isolate, "QUIT").ToLocalChecked());
                break;
            default:
                args.GetReturnValue().Set(uint32_t(-1));
                break;
            }
        }
    }

    void screenColor(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();

        // Check the number of arguments passed.
        if (args.Length() < 3)
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        // Check argument types
        if (!args[0]->IsNumber())
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Get the arguments ----------------------
        int RGB_R = args[0].As<Number>()->Value();
        int RGB_G = args[1].As<Number>()->Value();
        int RGB_B = args[2].As<Number>()->Value();

        // ----------------------------------------
        SDL_Surface *screen = SDL_GetWindowSurface(window);
        Uint32 color = SDL_MapRGB(screen->format, RGB_R, RGB_G, RGB_B);
        SDL_FillRect(screen, NULL, color);
        SDL_UpdateWindowSurface(window);
    }

    void rect(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();
        // Check the number of arguments passed.
        if (args.Length() < 6)
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }
        // Check argument types
        if (!args[0]->IsNumber())
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Get the arguments ----------------------
        int RGB_R = args[0].As<Number>()->Value();
        int RGB_G = args[1].As<Number>()->Value();
        int RGB_B = args[2].As<Number>()->Value();

        int x = args[3].As<Number>()->Value();
        int y = args[4].As<Number>()->Value();
        int w = args[5].As<Number>()->Value();
        int h = args[6].As<Number>()->Value();

        // ----------------------------------------

        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = 10;
        rect.h = 10;

        SDL_Surface *screen = SDL_GetWindowSurface(window);
        Uint32 color = SDL_MapRGB(screen->format, RGB_R, RGB_G, RGB_B);
        SDL_FillRect(screen, &rect, color);
        const void *temp_screen = static_cast<const void *>(screen);
        std::stringstream ss;
        ss << temp_screen;
        std::string str_screen = ss.str();
        std::cout << str_screen;

        args.GetReturnValue().Set(String::NewFromUtf8(isolate, str_screen.c_str()).ToLocalChecked());
        // std::cout << &rect;
        // SDL_UpdateWindowSurface(window);
    }

    void blit(const FunctionCallbackInfo<Value> &arg)
    {
        Isolate *isolate = arg.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();
        // Check the number of arguments passed.
        if (arg.Length() < 1)
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }
        // Check argument types
        if (!arg[0]->IsString())
        {
            isolate->ThrowException(
                Exception::TypeError(
                    String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Get the arguments ----------------------
        v8::Local<v8::String> str = arg[0].As<v8::String>();
        char *charStr = new char[8192];
        (*str)->WriteUtf8(isolate, charStr);
        std::string str_screen = charStr;
        delete charStr;

        // ----------------------------------------

        SDL_Surface *screen = SDL_GetWindowSurface(window);
        SDL_Surface *temp_screen = SDL_LoadBMP(str_screen.c_str());
        SDL_BlitSurface(temp_screen, NULL, screen, NULL);
        SDL_UpdateWindowSurface(window);
    }

    void Initialise(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "init", reinterpret_cast<v8::FunctionCallback>(setup));
        NODE_SET_METHOD(exports, "event", reinterpret_cast<v8::FunctionCallback>(event));
        NODE_SET_METHOD(exports, "screenColor", reinterpret_cast<v8::FunctionCallback>(screenColor));
        NODE_SET_METHOD(exports, "rect", reinterpret_cast<v8::FunctionCallback>(rect));
        NODE_SET_METHOD(exports, "blit", reinterpret_cast<v8::FunctionCallback>(blit));
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialise);
}