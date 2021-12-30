#ifndef txt_h
#define txt_h
#include "Game.h"
#include <SDL2/SDL_ttf.h>

using namespace std;
class text
{
    private:
        TTF_Font* fnt;
        SDL_Color clr;
        SDL_Texture* msgtex;
        SDL_Rect rect;
        int texw = 0, texh = 0;
    public:
        text(const char* font, int sz, const char* msg, int x, int y, SDL_Color clr);
        ~text();
        void update();
        void render();
};
#endif