#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstdint>
#include <sstream>
// #include "SDL.h"
#include "SDL.h"
#include "../../../../Users/rishi/AppData/Local/node-gyp/Cache/17.0.1/include/node/node.h"

// Custom Classes
#include "./classes/Rect.cpp"
#include "./classes/Clock.cpp"

namespace nodesdl {
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
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int RGB_R;
    int RGB_G;
    int RGB_B;

    // bool checkArgs(const FunctionCallbackInfo<Value>&args, int numberOfArguments)
    // {
    //     if (args.Length() != numberOfArguments)
    //     {
    //         return false;
    //     }
    //     return true;
    // }

    void setup(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();
//        Local<Context> context = isolate->GetCurrentContext();

        // Check the number of arguments passed.
        if (args.Length() < 4) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        // Check argument types
        if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsString() || !args[3]->IsBoolean()) {
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
        delete[] charTitle;

        fullscreen = args[3].As<Boolean>()->Value();
        // ----------------------------------------

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        }

        if (fullscreen) {
            window = SDL_CreateWindow(stringTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
                                      height, SDL_WINDOW_RESIZABLE);
        } else {
            window = SDL_CreateWindow(stringTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
                                      height, 0);
        }
    }

    auto event(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "QUIT").ToLocalChecked());
                    break;
                default:
                    args.GetReturnValue().Set(uint32_t(-1));
                    break;
            }
        }
    }

    void screenColor(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();

        // Check the number of arguments passed.
        if (args.Length() < 3) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        // Check argument types
        if (!args[0]->IsNumber()) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Get the arguments ----------------------
        RGB_R = args[0].As<Number>()->Value();
        RGB_G = args[1].As<Number>()->Value();
        RGB_B = args[2].As<Number>()->Value();

        // ----------------------------------------
        SDL_Surface *screen = SDL_GetWindowSurface(window);
        Uint32 color = SDL_MapRGB(screen->format, RGB_R, RGB_G, RGB_B);
        SDL_FillRect(screen, NULL, color);
//        SDL_UpdateWindowSurface(window);
    }

    void rect(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();
        // Check the number of arguments passed.
        const int numberOfArguments = 6;
        if (args.Length() < numberOfArguments) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }
        // Check argument types
        for (int i = 0; i < numberOfArguments; i++) {
            if (!args[i]->IsNumber()) {
                isolate->ThrowException(
                        Exception::TypeError(
                                String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
                return;
            }
        }

        // Get the arguments ----------------------
        int x = args[0].As<Number>()->Value();
        int y = args[1].As<Number>()->Value();
        int w = args[2].As<Number>()->Value();
        int h = args[3].As<Number>()->Value();

        int RGB_R = args[4].As<Number>()->Value();
        int RGB_G = args[5].As<Number>()->Value();
        int RGB_B = args[6].As<Number>()->Value();

        // ----------------------------------------

        Rect newRect;
        Rect *rectPointer;
//        std::cout << "Provided width: " << w << std::endl;
        SDL_Surface *screen = SDL_GetWindowSurface(window);
        newRect.init(screen, x, y, w, h, RGB_R, RGB_G, RGB_B);

        rectPointer = &newRect; // created pointer to current rect class-object

        std::string str_rectPointer;
        std::stringstream ss;
        ss << rectPointer;
        ss >> str_rectPointer;
//        std::cout << "string stream: " << str_rectPointer << std::endl;
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, str_rectPointer.c_str()).ToLocalChecked());
    }

    void blit(const FunctionCallbackInfo<Value> &arg) {
        Isolate *isolate = arg.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();
        // Check the number of arguments passed.
        if (arg.Length() < 1) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }
        // Check argument types
        if (!arg[0]->IsString()) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }

        // Get the arguments ----------------------
        Local<String> raw_pointer = arg[0].As<String>();
        char *char_rawPointer = new char[8192];
        (*raw_pointer)->WriteUtf8(isolate, char_rawPointer);
        std::string str_pointer = char_rawPointer;
        delete char_rawPointer;
        // ----------------------------------------
        std::stringstream ss;
        ss << str_pointer;
        long long unsigned int i;
        ss >> std::hex >> i;
        Rect *myObj = reinterpret_cast<Rect *>(reinterpret_cast<int *>(i));
        myObj->blit(window);
    }

    void updateRect(const FunctionCallbackInfo<Value> &args) {
        Isolate *isolate = args.GetIsolate();

        // Check the number of arguments passed.
        if (args.Length() < 1) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        // Check argument types
        const int numberOfArguments = 8;
        if (!args[0]->IsString()) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
            return;
        }
        for (int i = 1; i < numberOfArguments; i++) {
            if (!args[i]->IsNumber()) {
                isolate->ThrowException(
                        Exception::TypeError(
                                String::NewFromUtf8(isolate, "Wrong arguments").ToLocalChecked()));
                return;
            }
        }

        // Get the arguments ----------------------
        Local<String> str_shape_temp = args[0].As<String>();
        char *charStr = new char[8192];
        (*str_shape_temp)->WriteUtf8(isolate, charStr);
        std::string str_shape = charStr;
        delete charStr;

        int x = args[1].As<Number>()->Value();
        int y = args[2].As<Number>()->Value();
        int w = args[2].As<Number>()->Value();
        int h = args[4].As<Number>()->Value();

        int RGB_R = args[5].As<Number>()->Value();
        int RGB_G = args[6].As<Number>()->Value();
        int RGB_B = args[7].As<Number>()->Value();


        Local<String> raw_pointer = args[0].As<String>();
        char *char_rawPointer = new char[8192];
        (*raw_pointer)->WriteUtf8(isolate, char_rawPointer);
        std::string str_pointer = char_rawPointer;
        delete char_rawPointer;
        // ----------------------------------------
        std::stringstream ss;
        ss << str_pointer;
        long long unsigned int i;
        ss >> std::hex >> i;
        Rect *myObj = reinterpret_cast<Rect *>(reinterpret_cast<int *>(i));
        myObj->update(x, y, w, h, RGB_R, RGB_G, RGB_B);
        // ----------------------------------------
//        int SDL_RenderClear(SDL_Renderer *renderer);
//
//        SDL_Surface *screen = SDL_GetWindowSurface(window);
//        SDL_Surface *temp_screen = SDL_LoadBMP(str_shape.c_str());
//        SDL_BlitSurface(temp_screen, NULL, screen, NULL);

        SDL_UpdateWindowSurface(window);
    }

    void clear() {
        SDL_Surface *screen = SDL_GetWindowSurface(window);
        Uint32 color = SDL_MapRGB(screen->format, RGB_R, RGB_G, RGB_B);
        SDL_RenderClear(renderer);
        SDL_FillRect(screen, NULL, color);
    }

    void update() {
        SDL_UpdateWindowSurface(window);
    }

    void getTick(const FunctionCallbackInfo<Value> &arg) {
        Isolate *isolate = arg.GetIsolate();

        Clock Time;
        Uint64 time = Time.getTicks();

        if (arg.Length() >= 1) {
            isolate->ThrowException(
                    Exception::TypeError(
                            String::NewFromUtf8(isolate, "Wrong number of arguments").ToLocalChecked()));
            return;
        }

        arg.GetReturnValue().Set(uint32_t(time));

    }

    void Initialise(Local<Object> exports) {
        NODE_SET_METHOD(exports, "init", reinterpret_cast<v8::FunctionCallback>(setup));
        NODE_SET_METHOD(exports, "event", reinterpret_cast<v8::FunctionCallback>(event));
        NODE_SET_METHOD(exports, "screenColor", reinterpret_cast<v8::FunctionCallback>(screenColor));
        NODE_SET_METHOD(exports, "rect", reinterpret_cast<v8::FunctionCallback>(rect));
        NODE_SET_METHOD(exports, "blit", reinterpret_cast<v8::FunctionCallback>(blit));
        NODE_SET_METHOD(exports, "updateRect", reinterpret_cast<v8::FunctionCallback>(updateRect));
        NODE_SET_METHOD(exports, "clear", reinterpret_cast<v8::FunctionCallback>(clear));
        NODE_SET_METHOD(exports, "getTick", reinterpret_cast<v8::FunctionCallback>(getTick));
        NODE_SET_METHOD(exports, "update", reinterpret_cast<v8::FunctionCallback>(update));
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialise);
}