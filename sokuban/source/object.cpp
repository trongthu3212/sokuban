#include "object.hpp"
#include "gamestate.hpp"
#include "gamemap.hpp"

#include <SDL2/sdl.h>

vec2d object::get_pos()
    {
        return pos;
    }
 object::object(GameMap *state_){
        gmap=state_;
    }

object::~object() {
        gmap->state->get_texture_manager()->Unload(texture);
    }

void player::OnKeyPress(int key_code) {
        vec2d moveAmount;

        switch(key_code){
            case SDLK_UP:
            {
                 moveAmount = vec2d(0, -1);
                 break;
            }
             case SDLK_DOWN:
            {
                 moveAmount = vec2d(0, 1);
                 break;
            }
             case SDLK_LEFT:
            {
                 moveAmount = vec2d(-1, 0);
                 break;
            }
             case SDLK_RIGHT:
            {
                 moveAmount = vec2d(1, 0);
                 break;
            }
             default:
                 break;

        }

        Move(moveAmount);
    }

bool object::Move(vec2d amount) {
    if (!gmap->foreground[pos.x + amount.x][pos.y + amount.y] || (gmap->foreground[pos.x + amount.x][pos.y + amount.y]->Move(amount))) {
        vec2d oldPos = pos;
        pos = pos + amount;

        std::swap(gmap->foreground[oldPos.x][oldPos.y], gmap->foreground[pos.x][pos.y]);

        return true;
    }

    return false;
}

void object::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = pos.x*32;
    dest_rect.y = pos.y*32;
    dest_rect.w = 32;
    dest_rect.h = 32;

    SDL_RenderCopy(gmap->state->get_renderer(), texture, NULL, &dest_rect);
}

 player::player(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("player.bmp");
        layer = ObjectLayerForeground;
    }

 box::box(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("box.bmp");
        layer = ObjectLayerForeground;
 }

 destination::destination(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("destination.bmp");
        layer = ObjectLayerBackground;
 }

 wall::wall(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("wall.bmp");
        layer = ObjectLayerForeground;
 }
