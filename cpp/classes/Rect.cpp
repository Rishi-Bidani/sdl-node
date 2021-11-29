//
// Created by rishi on 27-11-2021.
//
#include "SDL.h"
#include <iostream>

class Rect {
public:
    int x = 0;
    int y{};
    int width{};
    int height{};
    int RGB_R{};
    int RGB_G{};
    int RGB_B{};
    SDL_Surface *screen = nullptr;
    SDL_Rect rect{};

    SDL_Rect init(SDL_Surface *Window, int X, int Y, int Width, int Height, int red, int green, int blue) {
        screen = Window;

        x = X;
        y = Y;
        width = Width;
        height = Height;
        RGB_R = red;
        RGB_G = green;
        RGB_B = blue;

        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;

        Uint32 color = SDL_MapRGB(screen->format, RGB_R, RGB_G, RGB_B);
        SDL_FillRect(screen, &rect, color);

        return rect;
    }

    SDL_Rect update(int X, int Y, int Width, int Height, int red, int green, int blue) {
        x = X;
        y = Y;
        width = Width;
        height = Height;
        RGB_R = red;
        RGB_G = green;
        RGB_B = blue;

        rect.x = X;
        rect.y = Y;
        rect.w = Width;
        rect.h = Height;
        Uint32 color = SDL_MapRGB(screen->format, RGB_R, RGB_G, RGB_B);
        SDL_FillRect(screen, &rect, color);

        return rect;
    }

    void blit(SDL_Window *window) {
        SDL_Surface *myRect = SDL_LoadBMP(reinterpret_cast<const char *>(&rect));
        SDL_BlitSurface(myRect, NULL, screen, NULL);
        SDL_UpdateWindowSurface(window);
    }

    SDL_Rect getRect() const {
        return rect;
    }

    int getWidth() const {
        std::cout << width;
        return width;
    }

};