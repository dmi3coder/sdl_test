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

void putPixel(SDL_Surface *surface, int x, int y,Uint32 pixel){
    int bytesPerPixel = surface->format->BytesPerPixel;
    Uint8 *newPixelPosition = (Uint8 *)surface->pixels + y * surface->pitch + x * bytesPerPixel;
    switch (bytesPerPixel) {
        case 1:
            *newPixelPosition = pixel;
            break;
        case 2:
            *(Uint16 *)newPixelPosition = pixel;
        case 4:
            *(Uint32 *)newPixelPosition = pixel;
        default:
            break;
    }
    
}

int main(int argc, const char * argv[]) {
    SDL_Window* window;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    window = SDL_CreateWindow("SDL testik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
    
    
    if(window == NULL){
        return -1;
    }
    SDL_Renderer* renderer = NULL;
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture * texture = SDL_CreateTexture(renderer,
                                              SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 640, 480);
    Uint32 * pixels = new Uint32[640 * 480];
    
    memset(pixels, 255, 640 * 480 * sizeof(Uint32));
    bool leftMouseButtonDown = false;
    while (true)
    {
            SDL_UpdateTexture(texture, NULL, pixels, 640 * sizeof(Uint32));
        
            SDL_Event event;
            if(SDL_PollEvent(&event)){
                switch (event.type) {
                    case SDL_QUIT:
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                        return 0;
                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_LEFT)
                            leftMouseButtonDown = false;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT)
                            leftMouseButtonDown = true;
                    case SDL_MOUSEMOTION:
                        if (leftMouseButtonDown)
                        {
                            int mouseX = event.motion.x;
                            int mouseY = event.motion.y;
                            for (int i = mouseY*640+mouseX -5 ; i < mouseY*640+mouseX + 5; i++) {
                                pixels[i] = 0x34cc85;
                            }
                            
                            
                            
                        }
                        break;
                }
    
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
            }
    }
}
