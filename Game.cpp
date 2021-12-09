#include "Game.h"
#include "SDL_image.h"
#include "TexManager.h"
#include "Gameboard.h"
#include "bg.h"
#include "Arrow.h"
#include "heart.h"
#include "UpArrow.h"

SDL_Renderer* Game::renderer = nullptr;
Gameboard* board;
Arrow* arro;
UpArrow *u1, *u2, *u3, *u4, *u5;
Background* bg;
Heart *h1, *h2, *h3;




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
    bg = new Background("img/background.png", 0, 0);
    board = new Gameboard("img/singlecz.png", 1216, 0);
    //tex = TexManager::Load("img/singlecz.png");

    arro = new Arrow("img/arrow.png", 50, 350);
    h1 = new Heart("img/heart.png", 0, 0);
    h2 = new Heart("img/heart.png", 70, 0);
    h3 = new Heart("img/heart.png", 140, 0);

    u1 = new UpArrow("img/uparrow.png", 500, 0);
    u2 = new UpArrow("img/uparrow.png", 570, 0);
    u3 = new UpArrow("img/uparrow.png", 640, 0);
    u4 = new UpArrow("img/uparrow.png", 710, 0);
    u5 = new UpArrow("img/uparrow.png", 780, 0);

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
    
    if(cnt == 0)
    {
        u1->update();
        u2->update();
        u3->update();
        u4->update();
        u5->update();
    }
    else if(cnt == 1)
    {
        u1->update();
        u2->update();
        u3->update();
        u4->update();
    }
    else if(cnt == 2)
    {
        u1->update();
        u2->update();
        u3->update();
    }
    else if(cnt == 3)
    {
        u1->update();
        u2->update();
    }
    else if(cnt == 4)
    {
        u1->update();
    }

    if(shtfg == 0) board->update();
    if(shtfg)   arro->update(board->gety(), &miss, &score, &cnt);
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

    if(cnt == 0)
    {
        u1->render();
        u2->render();
        u3->render();
        u4->render();
        u5->render();
    }
    else if(cnt == 1)
    {
       u1->render();
        u2->render();
        u3->render();
        u4->render();
    }
    else if(cnt == 2)
    {
        u1->render();
        u2->render();
        u3->render();
    }
    else if(cnt == 3)
    {
        u1->render();
        u2->render();
    }
    else if(cnt == 4)
    {
        u1->render();
    }
    board->render();
    arro->render();
   

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
                shtfg = 1;
            }
            else if(event.key.keysym.sym==SDLK_RIGHT)
            {
                board = new Gameboard("img/singlecz.png", 1216, 0);
                arro = new Arrow("img/arrow.png", 50, 350);
                shtfg = 0;
                cout << cnt << endl;
                if(miss == 3)
                {
                    cout << "chances exceeded " << score << endl;
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                }

                if(cnt == 5)
                {
                    cout << "out of arrows " << score << endl;
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                }
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