//
//  bg.cpp
//  Game
//
//  Created by Paras Vekariya on 09/12/21.
//

#include "bg.h"
#include "TexManager.h"

Background::Background(const char* texsheet, int inx, int iny)
{
    obtex = TexManager::Load(texsheet);
    x = inx;
    y = iny;
}

void Background::update()
{
    //x+=6;
    //y+=3;
    src.h = 800;
    src.w = 1300;
    src.x = 0;src.y = 0;
    dst.x = x;
    dst.y = y;
    dst.w = src.w;
    dst.h = src.h;
    
}

void Background::render()
{
    SDL_RenderCopy(Game::renderer, obtex,nullptr, &dst);
}
