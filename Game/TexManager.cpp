#include "TexManager.h"
#include "SDL2/SDL_image.h"

SDL_Texture* TexManager::Load(const char* path)
{
    SDL_Surface* sur = IMG_Load(path);
    SDL_Texture* text;
    text = SDL_CreateTextureFromSurface(Game::renderer, sur);
    SDL_FreeSurface(sur);
    return text;
}

void TexManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
