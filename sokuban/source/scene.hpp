#pragma once

#include <SDL2/SDL.h>
// hien 1 canh trong game (menu, level selection, in game, ...)
struct GameState;

class Scene {
protected:
    GameState *state;

public:
    Scene(GameState *state_) {
        state = state_;
    }

    GameState *GetState() {
        return state;
    }
    // ham duoc goi moi lan khi co su kien xay ra ( nhan phim, ...)
    virtual void Update(const SDL_Event &evt) = 0;
    // ham ve ket qua ra man hinh
    virtual void Draw() = 0;
};
