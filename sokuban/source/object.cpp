#include "object.hpp"
#include "gamestate.hpp"

#include <SDL2/sdl.h>

vec2d object::get_pos()
    {
        return pos;
    }
 object::object(GameState *state_){
        state=state_;
        texture = state->get_texture_manager()->Load("castle.bmp");
    }

object::~object() {
        state->get_texture_manager()->Unload(texture);
    }
void player::OnKeyPress(int key_code) {

        switch(key_code){
            case SDLK_UP:
            {
                 pos.y=pos.y-1;
                 break;
            }
             case SDLK_DOWN:
            {
                  pos.y=pos.y+1;
                 break;
            }
             case SDLK_LEFT:
            {
                 pos.x=pos.x-1;
                 break;
            }
             case SDLK_RIGHT:
            {
                pos.x=pos.x+1;
                 break;
            }
             default:
                 break;

        }
    }

void object::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = pos.x*32;
    dest_rect.y = pos.y*32;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(state->get_renderer(), texture, NULL, &dest_rect);
}
