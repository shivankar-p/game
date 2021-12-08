#include "Arrow.h"
#include "TexManager.h"

Arrow::Arrow(const char* texsheet, int inx, int iny)
{
    obtex = TexManager::Load(texsheet);
    x = inx;
    y = iny;
    src.h = 64;
    src.w = 64;
    src.x = 0;src.y = 0;
    dst.x = x;
    dst.y = y;
    dst.w = src.w*2;
    dst.h = src.h*2;
}

void Arrow::update()
{
    x+=5;
    //y+=3;
    
}

void Arrow::render()
{
    SDL_RenderCopy(Game::renderer, obtex,nullptr, &dst);
}
