//
//  UpArrow.h
//  Game
//
//  Created by Paras Vekariya on 11/12/21.
//

#ifndef uparr
#define uparr

#include "Game.h"

class UpArrow
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        UpArrow(const char* texsheet, int inx, int iny);
        ~UpArrow();
        void update();
        void render();
};

#endif /* UpArrow_h */
