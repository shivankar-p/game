#include "Arrow.h"
#include "TexManager.h"
#include "Music.h"

Music arr_se;

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

void Arrow::update(int pos, int* miss, int* scr, int *cnt)
{
    if(x+15 < 1140)
        {
            x += 15;
            if(x == 65) *cnt = *cnt+1;
        }
        else
        {
            //if(x > 1300)   return;
            int brdpos = pos;
            if(brdpos < 308 || brdpos > 410)
            {
                //cout << "miss" << endl;
                if(x < 1140)
                {
                    x = 1140;
                    if(*miss < 2 && *cnt < 4) arr_se.playmusic("song/blow.mp3", 2000);
                    *miss = *miss+1;
                    
                }
                //arr_se.playmusic("song/miss.mp3", 2000);
                x += 1;
            }
            else if(brdpos <= 320 || brdpos >= 398)
            {
                //cout << "Black" << endl;
                if(x < 1173)
                {
                    *scr = *scr + 4;
                    arr_se.playmusic("song/newhit.mp3", 1000);
                }
                //cout << *scr << endl;
                x = 1173;
                
            }
            else if(brdpos <= 336 || brdpos >= 382)
            {
                //cout << "Blue" << endl;
                if(x < 1162)
                {
                    *scr = *scr + 6;
                    arr_se.playmusic("song/newhit.mp3", 100);
                }
                     //cout << *scr << endl;
                x = 1162;
            }
            else if(brdpos <= 348 || brdpos >= 366)
            {
                //cout << "Red" << endl;
                if(x < 1151)
                {
                    *scr = *scr + 8;
                    arr_se.playmusic("song/newhit.mp3", 100);
                }
                 //cout << *scr << endl;
                x = 1151;
            }
            else
            {
                //cout << "Yellow" << endl;
                if(x < 1140)
                {
                    *scr = *scr + 10;
                    arr_se.playmusic("song/newhit.mp3", 1000);
                }
                 //cout << *scr << endl;
                x = 1140;
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
