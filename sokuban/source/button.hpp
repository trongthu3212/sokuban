#pragma once

#include <SDL2/SDL.h>
#include "object.hpp"
#include "vec2d.hpp"
#include <string>

struct GameState;

class Button {
protected:
    SDL_Texture*img;
    GameState*state;
    vec2d position;

public:
    Button(GameState *state_,std::string path);

    virtual void Draw() {}
    virtual void Execute() {}
};
