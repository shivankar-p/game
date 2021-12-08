#ifndef objhdr
#define objhdr
#include "Game.h"

class Gameboard
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        Gameboard(const char* texsheet, int inx, int iny);
        ~Gameboard();
        void update();
        void render();
};
#endif