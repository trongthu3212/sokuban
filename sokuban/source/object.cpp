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
                if (!state->objs[pos.x][pos.y - 1].empty()) {
                    for(int k=0;k<state->objs[pos.x][pos.y - 1].size();k++){
                        state->objs[pos.x][pos.y -1][k]->Advance(vec2d(0, -1));

                    }
                }

                 pos.y=pos.y-1;
                 break;
            }
             case SDLK_DOWN:
            {
                 if (!state->objs[pos.x][pos.y + 1].empty()) {
                   for(int k=0;k<state->objs[pos.x][pos.y + 1].size();k++){
                        state->objs[pos.x][pos.y +1][k]->Advance(vec2d(0, 1));

                    }
                }
                  pos.y=pos.y+1;
                 break;
            }
             case SDLK_LEFT:
            {
                 if (!state->objs[pos.x-1][pos.y].empty()) {
                   for(int k=0;k<state->objs[pos.x-1][pos.y].size();k++){
                        state->objs[pos.x-1][pos.y][k]->Advance(vec2d(-1, 0));

                    }

                }
                 pos.x=pos.x-1;
                 break;
            }
             case SDLK_RIGHT:
            {
                 if (!state->objs[pos.x+1][pos.y].empty()) {
                 for(int k=0;k<state->objs[pos.x+1][pos.y ].size();k++){
                        state->objs[pos.x+1][pos.y][k]->Advance(vec2d(1, 0));

                    }
;
                }
                pos.x=pos.x+1;
                 break;
            }
             default:
                 break;

        }

        std::vector<object*> &obj_at_old = state->objs[start.x][start.y];
        std::vector<object*>::iterator ite = std::find(obj_at_old.begin(), obj_at_old.end(), this);
        if (ite != obj_at_old.end()){
            obj_at_old.erase(ite);
            state->objs[pos.x][pos.y].push_back(this);
        }
    }

void object::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = pos.x*32;
    dest_rect.y = pos.y*32;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(state->state->get_renderer(), texture, NULL, &dest_rect);
}

 player::player(GameMap *state_) :object(state_){
        texture = state->state->get_texture_manager()->Load("player.bmp");
    }

 box::box(GameMap *state_) :object(state_){
        texture = state->state->get_texture_manager()->Load("box.bmp");
 }

 destination::destination(GameMap *state_) :object(state_){
        texture = state->state->get_texture_manager()->Load("destination.bmp");
 }

 wall::wall(GameMap *state_) :object(state_){
        texture = state->state->get_texture_manager()->Load("wall.bmp");
 }
