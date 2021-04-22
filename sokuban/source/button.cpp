#include "button.hpp"
#include "gamestate.hpp"

Button::Button(GameState *state_,std::string path)
    : state(state_) {
    img = state_->get_texture_manager()->Load(path);
}
