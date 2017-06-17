//
//  main.cpp
//  sdller
//
//  Created by j4c0re on 6/17/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>


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
    
    SDL_StartTextInput();
    
    while (!done) {
        SDL_Event event;
        if(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:
                    done = SDL_TRUE;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_Rect rect;
                    rect.x = event.button.x;
                    rect.y = event.button.y;
                    rect.w = 50;
                    rect.h = 50;
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    
                    SDL_RenderClear(renderer);
                    
                    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                    SDL_RenderFillRect(renderer, &rect);
                    SDL_RenderPresent(renderer);
                    
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
    }
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    return 0;
}
