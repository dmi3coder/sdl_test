//
//  main.cpp
//  sdller
//
//  Created by j4c0re on 6/17/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {
    SDL_Window* window;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("Encrypto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    if(window == NULL){
        return -1;
    }
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    
    SDL_RenderClear(renderer);
    
    SDL_Rect rect;
    
    rect.x = 50;
    rect.y = 50;
    rect.w = 50;
    rect.h = 50;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(8000);
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return 0;
}
