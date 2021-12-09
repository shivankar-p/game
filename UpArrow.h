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
#endif