#ifndef game_hdr
#define game_hdr

#include<bits/stdc++.h>
#include"SDL.h"

using namespace std;

class Game
{
    private:
        bool is_running;
        SDL_Window *window;
        SDL_Texture *tex;
        SDL_Rect src, dst;
        int cnt = 0;
        int shtfg = 0;
    public:
        Game();
        ~Game();
        void init(const char* title, int x, int y, int w, int h, bool fullscrn);
        void update();
        void render();
        void clean();
        void handle_events();
        bool running();
        static SDL_Renderer* renderer;

};

#endif