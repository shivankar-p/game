//
//  Music.cpp
//  Game
//
//  Created by Paras Vekariya on 11/12/21.
//

#include "Music.h"
#include "SDL2/SDL.h"
#include<bits/stdc++.h>

using namespace std;

Music::Music()
{
    SDL_Init(SDL_INIT_AUDIO);
    
    int audiorate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 1;
    int audio_buffers = 4096;
        
    if(Mix_OpenAudio(audiorate, audio_format, audio_channels, audio_buffers) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "couldn't inti audio: %s", Mix_GetError());
        exit(-1);
    }
}

Music::~Music()
{
    
}

void Music::addsound(const char* path)
{
    Mix_Chunk* temp = Mix_LoadWAV(path);
        
        if(temp != nullptr)
        {
            mse.push_back(temp);
            std::cout << (mse.size()-1) << " .sound loaded " << path << "\n";
        }
        else
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "couldn't inti audio: %s", Mix_GetError());
        }
}

void Music::foo(const char* path, int del)
{
    Mix_Music* t = Mix_LoadMUS(path);
    Mix_PlayMusic(t, -1);
    std::cout<<("music is%s playing.\n");
    if(Mix_PlayingMusic())
        std::cout<< "p\n";
    else
        std::cout<<" not";
    SDL_Delay(del);
    Mix_HaltMusic();
    Mix_FreeMusic(t);
    t = NULL;
}

void Music::playmusic(const char* path, int del)
{
    std::thread th1(Music::foo, path, del);
    th1.detach();
}

/*void Music::playsound(const int which)
{
//    Mix_PlayChannel(<#channel#>, <#chunk#>, <#loops#>)
    Mix_PlayChannel(-1, mse[which], 0);
    std::cout << "sound played" << which << "\n";

    Mix_Music* temp = Mix_LoadMUS(path);
    mse.push_back(temp);
    Mix_Chunk* t = Mix_LoadWAV(p);
    Mix_PlayChannel(-1, t, 1)
}*/

void Music::plays(const char* p)
{
    Mix_Chunk* tmp = Mix_LoadWAV(p);
    if(tmp != nullptr)
    {
        std::cout <<" song added\n";
        Mix_PlayChannel(-1, tmp, 0);
    }
    else
        std::cout<< "lund bsdka\n";
}
