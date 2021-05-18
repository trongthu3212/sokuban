#pragma once
#include <sdl2/sdl.h>
#include "resman.hpp"
#include "gamescene.hpp"
#include "menu_scene.hpp"

// Biểu hiện một thể thống game hoàn chỉnh
struct GameState {
private:
    friend class StartButton;
    friend class HomeButton;
    friend class SaveButton;
    friend class LevelSelectButton;

    SDL_Window *window;         // Cửa sổ chính trò chơi
    SDL_Renderer *renderer;     // Renderer chính trò chơi
    TextureManager manager;     // Quản lý ảnh trò chơi

    GameScene *gameScene;       // Màn game
    MenuScene *menuScene;       // Màn menu
    Scene *currentScene ;       // Màn hiện tại người chơi đang ở

    bool saveLoadedFirst;       // Biến để check nếu lần đầu người chơi mở game, save đã được load lại chưa.

public:
    GameState();
    ~GameState();

    SDL_Renderer *get_renderer();
    TextureManager *get_texture_manager();

    void loop();
};
