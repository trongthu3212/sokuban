#include "gamestate.hpp"
#include <fstream>
#include "gamemap.hpp"
#include<iostream>

GameState::GameState() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Sokuban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 750, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    manager = TextureManager(renderer);

    gameScene = new GameScene(this);
}

GameState::~GameState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    delete gameScene;
}

SDL_Renderer *GameState::get_renderer() {
    return renderer;
}

TextureManager *GameState::get_texture_manager() {
    return &manager;
}

void GameState::loop() {
    SDL_Event event;

  while(true){
      SDL_RenderClear(renderer);

      while( SDL_PollEvent( &event ) ){
        /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
        gameScene->Update(event);
      }

      gameScene->Draw();
      SDL_RenderPresent(renderer);
  }

}
