#include "GameObject.h"
#include "TexManager.h"

GameObject::GameObject(const char* texsheet, int inx, int iny)
{
    obtex = TexManager::Load(texsheet);
    x = inx;
    y = iny;
}

void GameObject::update()
{
    x++;
    y++;
    src.h = 32;
    src.w = 32;
    src.x = 0;src.y = 0;
    dst.x = x;
    dst.y = y;
    dst.w = src.w*2;
    dst.h = src.h*2;
}

void GameObject::render()
{
    SDL_RenderCopy(Game::renderer, obtex,nullptr, &dst);
}

