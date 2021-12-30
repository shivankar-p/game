//
//  bg.h
//  Game
//
//  Created by Paras Vekariya on 11/12/21.
//

#ifndef bgrd
#define bgrd
#include "Game.h"

class Background
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        Background(const char* texsheet, int inx, int iny);
        ~Background();
        void update();
        void render();
};
#endif
