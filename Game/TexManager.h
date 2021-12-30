#ifndef texman
#define texman

#include "Game.h"
class TexManager
{
    public:
        static SDL_Texture* Load(const char* path);
        static void Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest);

};

#endif