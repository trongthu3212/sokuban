#include "object.hpp"
#include "gamestate.hpp"
#include "gamemap.hpp"

#include <SDL2/sdl.h>

vec2d object::get_pos()
    {
        return pos;
    }
 object::object(GameMap *state_){
        state=state_;
        texture = state->state->get_texture_manager()->Load("castle.bmp");
    }

object::~object() {
        state->state->get_texture_manager()->Unload(texture);
    }
void player::OnKeyPress(int key_code) {
        if (!moved) {
            moved = true;
        } else {
            return;
        }

        vec2d start = pos;
        switch(key_code){
            case SDLK_UP:
            {
                if (state->objs[pos.x][pos.y - 1] != NULL) {
                    return;
                }

                 pos.y=pos.y-1;
                 break;
            }
             case SDLK_DOWN:
            {
                 if (state->objs[pos.x][pos.y + 1] != NULL) {
                    return;
                }
                  pos.y=pos.y+1;
                 break;
            }
             case SDLK_LEFT:
            {
                 if (state->objs[pos.x-1][pos.y] != NULL) {
                    return;
                }
                 pos.x=pos.x-1;
                 break;
            }
             case SDLK_RIGHT:
            {
                 if (state->objs[pos.x+1][pos.y] != NULL) {
                    return;
                }
                pos.x=pos.x+1;
                 break;
            }
             default:
                 break;

        }

        object *oldobj = state->objs[start.x][start.y];
        state->objs[start.x][start.y]= NULL;
        state->objs[pos.x][pos.y]= oldobj;
    }

void object::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = pos.x*32;
    dest_rect.y = pos.y*32;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(state->state->get_renderer(), texture, NULL, &dest_rect);
}
