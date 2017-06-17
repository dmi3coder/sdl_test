//
//  main.cpp
//  sdller
//
//  Created by j4c0re on 6/17/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "looper.hpp"


char *composition;
Sint32 cursor;
Sint32 selection_len;

int main(int argc, const char * argv[]) {
    SDL_Window* window;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("SDL testik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    if(window == NULL){
        return -1;
    }
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    
    
    SDL_RenderPresent(renderer);
    
    SDL_bool done = SDL_FALSE;
    
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    double x = 0;
    double y = 50;
    
    while (true)
    {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        
        deltaTime = (double)((NOW - LAST)*1000 / SDL_GetPerformanceFrequency() );
//        x += deltaTime;
        
//        if (x > 640)  x =0;

            SDL_Event event;
            if(SDL_PollEvent(&event)){
                switch (event.type) {
                    case SDL_QUIT:
                        return 0;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.scancode) {
                            case 79:
                                x += 10;
                                break;
                            case 80:
                                x -= 10;
                                break;
                            case 81:
                                y += 10;
                                break;
                            case 82:
                                y -= 10;
                                
                            default:
                                break;
                        }
                        std::cout << event.key.keysym.scancode << std::endl;
                        break;
                    case SDL_TEXTEDITING:
                        composition = event.text.text;
                        cursor = event.edit.start;
                        selection_len = event.edit.length;
                        break;
                        
                    default:
                        break;
                }
        }

        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 50;
        rect.h = 50;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        SDL_Texture *img = NULL;
        SDL_Surface* loadedSurface = IMG_Load( "./image.png" );
        img = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_RenderCopy(renderer, img, NULL, &rect);
        
        SDL_RenderPresent(renderer);

    
    }
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return 0;
}
