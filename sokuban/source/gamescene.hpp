#pragma once

#include "scene.hpp"

class GameMap;

class GameScene: public Scene {
private:
    GameMap *gmap;
    int level=1;

public:
    GameScene(GameState *state_);
    ~GameScene();

    void Update(const SDL_Event &evt) override;
    void Draw() override;
};
