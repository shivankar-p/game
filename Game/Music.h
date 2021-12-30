//
//  Music.h
//  Game
//
//  Created by Paras Vekariya on 11/12/21.
//

#ifndef Music_h
#define Music_h

#include <vector>
#include "SDL_mixer.h"
#include <stdio.h>


class Music
{
public:
    Music();
    ~Music();
    void addsound(const char* path);
    void playsound(const int which);
    static void playmusic(const char* path, int del);
    static void foo(const char* path, int del);
    static void plays(const char* p);
     
    
private:
    std::vector<Mix_Chunk*> mse;
    
};
#endif /* Music_h */
