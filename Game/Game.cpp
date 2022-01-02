#include <bits/stdc++.h>
#include "Game.h"
#include "SDL2/SDL_image.h"
#include "TexManager.h"
#include "Gameboard.h"
#include "Arrow.h"
#include "bg.h"
#include "heart.h"
#include "UpArrow.h"
#include "Music.h"
#include "text.h"

using namespace std;


Gameboard* board;
Music se;
Arrow* arro;
Background* bg;
SDL_Renderer* Game::renderer = nullptr;
UpArrow *u;
Heart *h1, *h2, *h3, *rkey;
text *txt, *arrtxt, *gameover, *scr, *ret, *rettext, *hiscr, *hsc_top_r;


Game :: Game ()
{
    
}
Game :: ~Game()
{
    
}

void Game :: init(const char* title, int x, int y, int w, int h, bool fullscrn)
{
    int flags = 0;
        if(fullscrn) flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {
            window = SDL_CreateWindow(title, x, y, w, h, flags);
            
            /*sur = SDL_GetWindowSurface(window);
            bg = SDL_LoadBMP("img/background.png");
            SDL_BlitSurface(bg, nullptr, sur, nullptr);
            SDL_UpdateWindowSurface(window);
            SDL_FreeSurface(bg);*/

            renderer = SDL_CreateRenderer(window, -1, 0);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            is_running = true;

        }
        else
        {
            is_running = false;
        }

        /*CreateSDL_Surface* sur = IMG_Load("img/target.png");
        tex = SDL_CreateTextureFromSurface(renderer, sur);
        SDL_FreeSurface(sur);*/
    
//        se.addsound("/Users/paras/Desktop/Game/Game/song/arrowsound.mp3");
//    se.addsound("/Users/paras/Desktop/Game/Game/song/metal_gear_solid.mp3");
//    se.addsound("/Users/paras/Desktop/Game/Game/song/naya_wala.mp3");
        bg = new Background("img/background.png", 0, 0);
        board = new Gameboard("img/singlecz.png", 1216, 0);
        //tex = TexManager::Load("img/singlecz.png");

        arro = new Arrow("img/arrow.png", 50, 350);
        h1 = new Heart("img/heart.png", 0, 0);
        h2 = new Heart("img/heart.png", 70, 0);
        h3 = new Heart("img/heart.png", 140, 0);

        u = new UpArrow("img/uparrow.png", 630, 0);
        rkey = new Heart("img/rkey.png", 600, 620);
        txt = new text("font/slkscrb.ttf", 50, ("SCORE:"+to_string(score)).c_str(), 0, 50, {0,0,0});
        ret = new text("font/serif.ttf", 30, "Press", 500, 630, {0,0,0});
        rettext = new text("font/serif.ttf", 30, "to Retry", 670, 630, {0,0,0});
        arrtxt = new text("font/slkscrb.ttf", 35, ("X"+to_string(5-cnt)).c_str(), 680, 20, {0,0,0});
        hiscr = new text("font/lcd.ttf", 35, "New Highscore!", 500, 450, {0,0,0});
        hsc_top_r = new text("font/lcd.ttf", 35, ("Highscore:"+to_string(mx)).c_str(), 950, 25, {0,0,0});
}

void Game :: update()
{
    bg->update();
        if(miss == 0)
        {
            h1->update();
            h2->update();
            h3->update();
        }
        else if(miss == 1)
        {
            h1->update();
            h2->update();
        }
        else if(miss == 2)
        {
            h1->update();
        }
        
        if(cnt <= 5 && miss < 3)
        {
            u->update();
            if(shtfg == 0) board->update();
            if(shtfg)   arro->update(board->gety(), &miss, &score, &cnt);
            txt->update();
            arrtxt->update();
            scr->update();
        }
        else
        {
            gameover = new text("font/slkscrb.ttf", 50,"GAME OVER", 450, 350, {255,0,0});
            scr = new text("font/slkscrb.ttf", 50, ("SCORE:"+to_string(score)).c_str(), 500, 400, {0,0,0});
            gameover->update();
            scr->update();
            if(hscorefg)   hiscr->update();
            ret->update();
            rkey->update();
            rettext->update();
        }
        hsc_top_r = new text("font/lcd.ttf", 35, ("Highscore:"+to_string(mx)).c_str(), 950, 25, {0,0,0});
        hsc_top_r->update();
}   

void Game :: render()
{
        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, tex, nullptr , &dst);
        bg->render();
        if(miss == 0)
        {
            h1->render();
            h2->render();
            h3->render();
        }
        else if(miss == 1)
        {
            h1->render();
            h2->render();
        }
        else if(miss == 2)
        {
            h1->render();
        }

        if(cnt <= 5 && miss < 3)
        {
            u->render();
            board->render();
            arro->render();
            txt->render();
            arrtxt->render();
        }
        else
        {
            gameover = new text("font/slkscrb.ttf", 50,"GAME OVER", 450, 350, {255,0,0});
            scr = new text("font/slkscrb.ttf", 50, ("SCORE:"+to_string(score)).c_str(), 500, 400, {0,0,0});
            gameover->render();
            scr->render();
            if(hscorefg)   hiscr->render();
            ret->render();
            rkey->render();
            rettext->render();
        }
        hsc_top_r->render();
       

        SDL_RenderPresent(renderer);
}

void Game :: clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game :: handle_events()
{
    SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                is_running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym==SDLK_SPACE)
                {
                    /*if(!shtfg)
                    {
                        se.playmusic("song/arrsht.mp3", 3000);
                    }*/
                    cout << score << endl;
                    shtfg = 1;
                    //std::cout << "sound played" << "\n";
                }
                else if(event.key.keysym.sym==SDLK_RIGHT)
                {
                    board = new Gameboard("img/singlecz.png", 1216, 0);
                    arro = new Arrow("img/arrow.png", 50, 350);
                    txt = new text("font/slkscrb.ttf", 50, ("SCORE:"+to_string(score)).c_str(), 0, 50, {0,0,0});
                    arrtxt = new text("font/slkscrb.ttf", 35, ("X"+to_string(5-cnt)).c_str(), 680, 20, {0,0,0});
                    shtfg = 0;
                    //cout << cnt << endl;
                    /*if(miss == 3)
                    {
                        cout << "chances exceeded " << score << endl;
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                    }*/

                    if(cnt >= 5 || miss >= 3)
                    {
                        cout << "out of arrows " << score << endl;
                        cnt = 6;
                        if(score > mx)
                        {
                            hscorefg = 1;
                            mx = score;
                        }
                        
                        /*SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();*/
                    }
                }
                else if(event.key.keysym.sym==SDLK_r)
                {
                    cnt = 0;
                    miss = 0;
                    score = 0;
                    shtfg = 0;
                    hscorefg = 0;
                    board = new Gameboard("img/singlecz.png", 1216, 0);
                    arro = new Arrow("img/arrow.png", 50, 350);
                    txt = new text("font/slkscrb.ttf", 50, ("SCORE:"+to_string(score)).c_str(), 0, 50, {0,0,0});
                    txt->update();
                    txt->render();
                    
                    arrtxt = new text("font/slkscrb.ttf", 35, ("X"+to_string(5-cnt)).c_str(), 680, 20, {0,0,0});
                    arrtxt->update();
                    arrtxt->render();
                }
                break;
            default:
                break;
        }
}

bool Game :: running()
{
    return is_running;
}
