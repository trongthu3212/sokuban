#pragma once
#include "object.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <SDL2/SDL.h>
struct GameState;
struct GameMap{
    object* background[200][200];
    object* foreground[200][200];

    player *control;
   SDL_Texture* ground;

    GameState * state;
    GameMap(GameState* state_);

    int height;
    int width;

    void draw();
    void load(std::string path);

};
