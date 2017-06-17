//
//  looper.cpp
//  sdller
//
//  Created by j4c0re on 6/17/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#include "looper.hpp"
#include <chrono>

using namespace std::chrono;
int64_t currentTime = -1;

int64_t getCurrentTime(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int64_t DeltaLooper::getDeltaTime() {
    if(currentTime == -1){
        currentTime = getCurrentTime();
        return 0;
    }
    int64_t oldTime = currentTime;
    currentTime = getCurrentTime();
    int64_t delta = currentTime - oldTime;
    return delta;
}
