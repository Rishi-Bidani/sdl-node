//
// Created by rishi on 03-12-2021.
//

#include "SDL.h"
#include <iostream>
#include <string>
#include "../../src/SDL2_image/include/SDL_image.h"

class Image {
public:
    static SDL_Texture *load(SDL_Renderer *renderer, const std::string &path, double x, double y) {
        SDL_Surface *image = IMG_Load(path.c_str());
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
        return texture;
//        std::cout << "load renderer: " << renderer << std::endl;


        //The final optimized image
//        SDL_Surface *optimizedSurface = NULL;

        //Load image at specified path
//        SDL_Surface *loadedSurface = IMG_Load(path.c_str());
//        loadImage = loadedSurface;
//
//        if (loadedSurface == NULL) {
//            printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//        } else {
//            //Convert surface to screen format
//            optimizedSurface = SDL_ConvertSurface(loadedSurface, screen->format, 0);
//            if (optimizedSurface == NULL) {
//                printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//            }
//            loadImage = optimizedSurface;
//            //Get rid of old loaded surface
//            SDL_FreeSurface(loadedSurface);
//        }
//        loadImage = IMG_Load(path.c_str());
//        loadImage = SDL_LoadBMP(path.c_str());
//        SDL_BlitSurface(loadImage, NULL, screen, NULL);
//        SDL_FreeSurface(loadImage);
    }

    static void blit(SDL_Surface *window, SDL_Renderer *renderer, SDL_Texture *texture) {
//        std::cout << "blit texture: " << texture << std::endl;
        SDL_RenderCopy(renderer, texture, NULL, NULL);
//        SDL_RenderPresent(renderer);
//        std::cout << SDL_GetError();
    }
};