#ifndef tile_mp
#define tile_mp
#include "Game.h"
class Map
{
    private:
        SDL_Rect src, dst;
    public:
        Map();
        ~Map();
        void LoadMap();
        void DrawMap();
};
#endif
