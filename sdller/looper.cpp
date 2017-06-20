//
//  looper.cpp
//  sdller
//
//  Created by j4c0re on 6/17/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#include "looper.hpp"
#include <SDL2/SDL.h>

Uint64 nowTime = 0;
Uint64 lastTime = 0;

double DeltaLooper::getDeltaTime() {
    nowTime =  SDL_GetPerformanceCounter();
    if(lastTime == 0){
        lastTime = nowTime;
        return 0;
    }
    
    Uint64 deltaTime = nowTime - lastTime;
    return (double)deltaTime;
}
