//
// Created by rishi on 27-11-2021.
//
#include "SDL.h"
#include <iostream>

class Rect {
public:
    double x = 0;
    double y = 0;
    double width = 0;
    double height = 0;
    double RGB_R{};
    double RGB_G{};
    double RGB_B{};
    SDL_Surface *screen = nullptr;
    SDL_Rect rect{};

    SDL_Rect
    init(
            SDL_Surface *Window,
            SDL_Renderer *renderer,
            double X, double Y, double Width, double Height, double red,
            double green, double blue
    ) {
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

        SDL_RenderDrawRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, RGB_R, RGB_G, RGB_B, 255);
        SDL_RenderFillRect(renderer, &rect);

        return rect;
    }

    SDL_Rect update(double X, double Y, double Width, double Height, double red, double green, double blue) {
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

    void blit(SDL_Window *window, SDL_Renderer *renderer) const {
        SDL_RenderDrawRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, RGB_R, RGB_G, RGB_B, 255);
        SDL_RenderFillRect(renderer, &rect);
    }
};