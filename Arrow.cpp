#include "Arrow.h"
#include "TexManager.h"
#include "Gameboard.h"
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

void Arrow::update(int pos, int* miss, int* scr)
{
    if(x+15 < 1140)  x += 15;
    else
    {
        if(x >= 1140)   return;
        int brdpos = pos;
        if(brdpos < 308 || brdpos > 410)
        {
            cout << "miss" << endl;
            *miss = *miss+1;
            while(x < 1300) x+=5;
        }
        else if(brdpos <= 320 || brdpos >= 398)
        {
            cout << "Black" << endl;
            x = 1173;
            *scr += 4;
        }
        else if(brdpos <= 336 || brdpos >= 382)
        {
            cout << "Blue" << endl;
            x = 1162;
            *scr += 6;
        }
        else if(brdpos <= 348 || brdpos >= 366)
        {
            cout << "Red" << endl;
            x = 1151;
            *scr += 8;
        }
        else
        {
            cout << "Yellow" << endl;
            x = 1140;
            *scr += 10;
        }

    }
    //y+=3;
    src.h = 64;
    src.w = 64;
    src.x = 0;src.y = 0;
    dst.x = x;
    dst.y = y;
    dst.w = src.w*2;
    dst.h = src.h*2;
    
}

void Arrow::render()
{
    SDL_RenderCopy(Game::renderer, obtex,nullptr, &dst);
}
