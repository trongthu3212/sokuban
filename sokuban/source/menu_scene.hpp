#pragma once

#include "gamestate.hpp"
#include "button.hpp"

class MenuScene;

class StartButton:public Button{
private:
    MenuScene *scene;


public:
    StartButton(GameState *state_,MenuScene*scene_)
        : Button(state_, "start.png") {
        scene = scene_;
    }

    void Execute() override;
};

class LevelSelectButton:public Button{
private:
    MenuScene *scene;

public:
    LevelSelectButton(GameState *state_,MenuScene*scene_)
        : Button(state_, "level.png") {
        scene = scene_;
    }

    void Execute() override;
};

class MenuScene:public Scene{
private :
    SDL_Texture *backgroundimg;
    LevelSelectButton selectBtn;
    StartButton startBtn;

public:
    MenuScene(GameState *state_);
    ~MenuScene();

    void Update(const SDL_Event &evt) override;
    void Draw() override;
    void SwitchMap();

};
