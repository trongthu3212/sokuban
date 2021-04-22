#include "button.hpp"
#include "gamestate.hpp"

Button::Button(GameState *state_,std::string path)
    : state(state_) {
    img = state_->get_texture_manager()->Load(path);
}

void Button::SetSize(const vec2d &size) {
    btnsize = size;
}

void Button::SetPosition(const vec2d &pos) {
    position = pos;
}

void Button::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = position.x;
    dest_rect.y = position.y;//gmap->start_pos.y + pos.y*gmap->boxsize;
    dest_rect.w = btnsize.x;
    dest_rect.h = btnsize.y;

    SDL_RenderCopy(state->get_renderer(), img, NULL, &dest_rect);
}

void Button::OnMousePressed(const int btn, const int mouseX, const int mouseY) {
    if (btn == SDL_BUTTON_LEFT) {
        if ((position.x <= mouseX) && (position.x + btnsize.x >= mouseX) &&
            (position.y <= mouseY) && (position.y + btnsize.y >= mouseY)) {
            Execute();
        }
    }
}
