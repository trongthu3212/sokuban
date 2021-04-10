#pragma once

#include <SDL2/SDL.h>

struct GameState;

class Scene {
private:
    GameState *state;

public:
    Scene(GameState *state_) {
        state = state_;
    }

    virtual void Update(const SDL_Event &evt) = 0;
    virtual void Draw() = 0;
};
