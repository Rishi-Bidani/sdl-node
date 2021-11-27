//
// Created by rishi on 27-11-2021.
//
#include "Rect.h"
#include "SDL.h"

class Rect {
public:
    int x;
    int y;
    int width;
    int height;
    int RGB_R;
    int RGB_G;
    int RGB_B;

    void init(int x, int y, int width, int height, int red, int green, int blue){
        x=x; y=y; width=width; height=height;
        RGB_R=red; RGB_G=green; RGB_B=blure;
        SDL_Rect rect;

        rect.x=x;
        rect.y=y;
        rect.width=width;
        rect.height=height;

    }
};