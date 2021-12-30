//
//  UpArrow.cpp
//  Game
//
//  Created by Paras Vekariya on 11/12/21.
//

#include <stdio.h>
#include "UpArrow.h"
#include "TexManager.h"

UpArrow::UpArrow(const char* texsheet, int inx, int iny)
{
    obtex = TexManager::Load(texsheet);
    x = inx;
    y = iny;
}

void UpArrow::update()
{
    src.h = 64;
    src.w = 64;
    src.x = 0;src.y = 0;
    dst.x = x;
    dst.y = y;
    dst.w = src.w;
    dst.h = src.h;
}

void UpArrow::render()
{
    SDL_RenderCopy(Game::renderer, obtex,nullptr, &dst);
}
