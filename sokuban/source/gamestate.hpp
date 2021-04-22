#pragma once
#include <sdl2/sdl.h>
#include "resman.hpp"
#include "gamescene.hpp"
#include "menu_scene.hpp"

struct GameState {
private:
    friend class StartButton;

    SDL_Window *window;
    SDL_Renderer *renderer;
    TextureManager manager;

    GameScene *gameScene;
    MenuScene *menuScene;
    Scene *currentScene ;

public:
    GameState();
    ~GameState();

    SDL_Renderer *get_renderer();
    TextureManager *get_texture_manager();

    void loop();
};
