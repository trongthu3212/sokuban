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
    menuScene= new MenuScene(this);
    currentScene =menuScene;

    saveLoadedFirst = false;
}

GameState::~GameState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    delete gameScene;
    delete menuScene;
}

SDL_Renderer *GameState::get_renderer() {
    return renderer;
}

TextureManager *GameState::get_texture_manager() {
    return &manager;
}

void GameState::loop() {
    SDL_Event event;
    bool should_quit = false;

  while(!should_quit){
      SDL_RenderClear(renderer);

      while( SDL_PollEvent( &event ) ){
          if (event.type == SDL_QUIT) {
             should_quit = true;
             break;
          }
        /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
        //gameScene->Update(event);
         currentScene->Update(event);
      }

      //gameScene->Draw();
      currentScene->Draw();
      SDL_RenderPresent(renderer);
  }

}
