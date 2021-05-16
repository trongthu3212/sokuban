#pragma once

#include "button.hpp"
#include "scene.hpp"

class GameMap;
class GameScene;

class RestartButton:public Button{
private:
    GameScene *scene;

public:
    RestartButton(GameState *state_,GameScene*scene_)
        : Button(state_, "restart.png") {
        scene = scene_;
    }

    void Execute() override;
};


class HomeButton: public Button {
private:
    GameScene *scene;


public:
    HomeButton(GameState *state_,GameScene*scene_)
        : Button(state_, "home.png") {
        scene = scene_;
    }

    void Execute() override;
};

class SaveButton:public Button{
private:
    GameScene *scene;
public:
    SaveButton(GameState *state_,GameScene*scene_)
        :Button(state_, "save.png"){
        scene = scene_;
        }
    void Execute() override;
};

class GameScene: public Scene {
private:
    GameMap *gmap;

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
};
