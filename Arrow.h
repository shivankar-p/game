#ifndef arr
#define arr
#include "Game.h"

class Arrow
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        Arrow(const char* texsheet, int inx, int iny);
        ~Arrow();
        void update();
        void render();
};
#endif