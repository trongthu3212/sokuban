#include "gamestate.hpp"
#include <fstream>
#include "gamemap.hpp"

GameState::GameState() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Sokuban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    manager = TextureManager(renderer);
}

GameState::~GameState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

SDL_Renderer *GameState::get_renderer() {
    return renderer;
}

TextureManager *GameState::get_texture_manager() {
    return &manager;
}

void GameState::loop() {
   GameMap mapp(this);
    mapp.load("map.txt");
    mapp.draw();
    SDL_RenderPresent(renderer);
}
