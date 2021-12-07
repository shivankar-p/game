#include "Game.h"
#include "SDL_image.h"
#include "TexManager.h"
#include "GameObject.h"

GameObject* board;

SDL_Renderer* Game::renderer = nullptr;



Game :: Game ()
{

}
Game :: ~Game()
{
    
}

void Game :: init(const char* title, int x, int y, int w, int h, bool fullscrn)
{
    int flags = 0;
    if(fullscrn) flags = SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, x, y, w, h, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        is_running = true;
    }
    else
    {
        is_running = false;
    }

    /* CreateSDL_Surface* sur = IMG_Load("img/target.png");
    tex = SDL_CreateTextureFromSurface(renderer, sur);
    SDL_FreeSurface(sur);*/
    board = new GameObject("img/target.png", 0, 0);
    tex = TexManager::Load("img/target.png");
}

void Game :: update()
{
    board->update();
}

void Game :: render()
{
    SDL_RenderClear(renderer);
    //SDL_RenderCopy(renderer, tex, nullptr , &dst);
    board->render();
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
        default:
            break;
    }
}

bool Game :: running()
{
    return is_running;
}