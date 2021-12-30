#ifndef objhdr
#define objhdr
#include "Game.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

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
        int gety();
};
#endif
