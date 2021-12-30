//
//  bg.hpp
//  Game
//
//  Created by Paras Vekariya on 09/12/21.
//

#ifndef bg_hpp
#define bg_hpp

#include "Game.h"
#include <stdio.h>

class Background
{
    private:
        int x,y;
        SDL_Texture* obtex;
        SDL_Rect src,dst;
        
    public:
        Background(const char* texsheet, int inx, int iny);
        ~Background();
        void update();
        void render();
};
#endif /* bg_hpp */
