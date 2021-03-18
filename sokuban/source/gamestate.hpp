#pragma once
#include <sdl2/sdl.h>
#include "resman.hpp"
#include"gamemap.hpp"

struct GameState {
    SDL_Window *window;
    SDL_Renderer *renderer;
    TextureManager manager;
    GameMap *x;

public:
    GameState();
    ~GameState();

    SDL_Renderer *get_renderer();
    TextureManager *get_texture_manager();

    void loop();
};
