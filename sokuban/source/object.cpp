#include "object.hpp"
#include "gamestate.hpp"

vec2d object::get_pos()
    {
        return pos;
    }

void player::OnKeyPress(int key_code) {
        if (key_code == KEY_DOWN) {
            pos.y=pos.y+1;
        }
        else if(key_code == KEY_UP){
            pos.y=pos.y-1;
        }
        else if(key_code == KEY_LEFT){
            pos.x=pos.x-1;

        }
        else if(key_code == KEY_RIGHT){
            pos.x=pos.x+1;
        }
    }

void object::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = pos.x;
    dest_rect.y = pos.y;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(state->get_renderer(), texture, NULL, &dest_rect);
}
