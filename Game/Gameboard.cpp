#include "Gameboard.h"
#include "TexManager.h"

Gameboard::Gameboard(const char* texsheet, int inx, int iny)
{
    obtex = TexManager::Load(texsheet);
    x = inx;
    y = iny;
}

void Gameboard::update()
{
    y += 5;
    if(y > 800)   y = 0;
    src.h = 64;
    src.w = 64;
    src.x = 0;src.y = 0;
    dst.x = x;
    dst.y = y;
    dst.w = src.w*2;
    dst.h = src.h*2;
    //x++;
//    y+=3;
//    src.h = 64;
//    src.w = 64;
//    src.x = 0;src.y = 0;
//    dst.x = x;
//    dst.y = y;
//    dst.w = src.w*2;
//    dst.h = src.h*2;
}

void Gameboard::render()
{
    SDL_RenderCopy(Game::renderer, obtex, nullptr, &dst);
}

int Gameboard::gety()
{
    return y;
}
