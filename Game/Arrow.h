#ifndef arr
#define arr
#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Arrow
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        Arrow(const char* texsheet, int inx, int iny);
        ~Arrow();
        void update(int pos, int* miss, int* scr, int *cnt);
        void render();
};
#endif
