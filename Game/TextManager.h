#ifndef textman_h
#define textman_h

#include "Game.h"
#include <SDL2/SDL_ttf.h>
class TextManager
{
    public:
        static SDL_Texture* Loadmsg(TTF_Font* fnt, const char* msg, SDL_Color clr);
        static void Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest);

};

#endif