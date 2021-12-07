#ifndef objhdr
#define objhdr
#include "Game.h"

class GameObject
{
    private:
        int x, y;
        SDL_Texture* obtex;
        SDL_Rect src, dst;
    public:
        GameObject(const char* texsheet, int inx, int iny);
        ~GameObject();
        void update();
        void render();
};
#endif