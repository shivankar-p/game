#include <stdio.h>
#include "text.h"
#include "TextManager.h"
#include <SDL2/SDL_ttf.h>

using namespace std;

text::text(const char* font, int sz, const char* msg, int x, int y, SDL_Color clr)
{
    TTF_Init();
    fnt = TTF_OpenFont(font, sz);
    msgtex = TextManager::Loadmsg(fnt, msg, clr);
    SDL_QueryTexture(msgtex, NULL, NULL, &texw, &texh);
    rect = { x, y, texw, texh };
}

void text::update()
{
    //x+=6;
    //y+=3;
    /*rect.x = 350;
    rect.y = 350;
    rect.w = 64;
    rect.h = 64;*/
    
}

void text::render()
{
    SDL_RenderCopy(Game::renderer, msgtex, nullptr, &rect);
}