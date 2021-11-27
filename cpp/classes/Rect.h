//
// Created by rishi on 27-11-2021.
//

#ifndef SDL_NODE_RECT_H
#define SDL_NODE_RECT_H


class Rect {
    int x;
    int y;
    int width;
    int height;
    int RGB_R;
    int RGB_G;
    int RGB_B;

    void init(int x, int y, int width, int height, int red, int green, int blue);
};


#endif //SDL_NODE_RECT_H
