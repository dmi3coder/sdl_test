//
//  View.hpp
//  sdller
//
//  Created by j4c0re on 6/25/17.
//  Copyright © 2017 dmi3coder. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class View{
    static int VISIBLE;
    static int INVISIBLE;
    static int GONE;
    
    static int ENABLED;
    static int DISABLED;
public:
    View(SDL_Renderer *renderer);
    void draw();
    
private:
    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;
    Uint32* mPixels;
};

#endif /* View_hpp */
