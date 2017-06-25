//
//  View.cpp
//  sdller
//
//  Created by j4c0re on 6/25/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#include "View.hpp"
#include <SDL2/SDL.h>



View::View(SDL_Renderer *rendered){
    this->mRenderer = rendered;
    this->mTexture = SDL_CreateTexture(rendered, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, 20, 20);
    mPixels = new Uint32[20*20];
    memset(mPixels, 0x34cc85, 20*20*sizeof(Uint32));
}

void View::draw(){
    SDL_UpdateTexture(mTexture, NULL, mPixels, 20 * sizeof(Uint32));
    SDL_Rect rect = SDL_Rect();
    rect.x = 10;
    rect.y = 10;
    rect.h = 20;
    rect.w = 20;
    
    SDL_RenderCopy(mRenderer, mTexture, NULL, &rect);
}
