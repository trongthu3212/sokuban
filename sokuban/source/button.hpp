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
    vec2d btnsize;

public:
    Button(GameState *state_,std::string path);

    void SetSize(const vec2d &size);
    void SetPosition(const vec2d &pos);

    virtual void Draw();
    virtual void Execute() {}

    virtual void OnMousePressed(const int btn, const int mouseX, const int mouseY);
};
