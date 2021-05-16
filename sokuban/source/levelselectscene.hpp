#pragma once

#include "button.hpp"
#include "scene.hpp"

class LevelSelectScene: public Scene {
private:
    SDL_Texture *restartTexture;
    RestartButton restartBtn;
    HomeButton homeBtn;
    SaveButton saveBtn;

    int level=1;

public:
    GameScene(GameState *state_);
    ~GameScene();
    friend class SaveButton;

    void Update(const SDL_Event &evt) override;
    void Draw() override;
    void SwitchMap();

    void Save();
    void Load();
};
