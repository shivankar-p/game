#include "TextManager.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>

SDL_Texture* TextManager::Loadmsg(TTF_Font* fnt, const char* msg, SDL_Color clr)
{
    SDL_Surface* sur = TTF_RenderText_Solid(fnt, msg , clr);
    SDL_Texture* text;
    text = SDL_CreateTextureFromSurface(Game::renderer, sur);
    SDL_FreeSurface(sur);
    return text;
}

void TextManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}