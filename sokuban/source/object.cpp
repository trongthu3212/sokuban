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

box::~box() {
    gmap->state->get_texture_manager()->Unload(boxNormal);
    gmap->state->get_texture_manager()->Unload(boxcolor);
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
// kiem tra vat can khi player di chuyen
bool object::Move(vec2d amount) {
    if (!gmap->foreground[pos.x + amount.x][pos.y + amount.y] || (gmap->foreground[pos.x + amount.x][pos.y + amount.y]->Move(amount))) {
        vec2d oldPos = pos;
        pos = pos + amount;

        std::swap(gmap->foreground[oldPos.x][oldPos.y], gmap->foreground[pos.x][pos.y]);

        return true;
    }

    return false;
}
// kiem tra lieu box co the di chuyen tiep hay khong
bool box::Move(vec2d amount){
        if (gmap->foreground[pos.x + amount.x][pos.y + amount.y]) {
            return false;
        }

        if(gmap->background[pos.x][pos.y]) {
            gmap->pointChecked--;
            texture=boxNormal;
        }

        vec2d oldPos = pos;
        pos = pos + amount;

         if(gmap->background[pos.x][pos.y]) {
            gmap->pointChecked++;
            texture=boxcolor;
        }


        std::swap(gmap->foreground[oldPos.x][oldPos.y], gmap->foreground[pos.x][pos.y]);

        return true;

}
// ham ve cua cac vat the
void object::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = gmap->start_pos.x + pos.x*gmap->boxsize;
    dest_rect.y = gmap->start_pos.y + pos.y*gmap->boxsize;
    dest_rect.w = gmap->boxsize;
    dest_rect.h = gmap->boxsize;

    SDL_RenderCopy(gmap->state->get_renderer(), texture, NULL, &dest_rect);
}

 player::player(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("player.png");
        layer = ObjectLayerForeground;
    }

 box::box(GameMap *state_) :object(state_){

        boxcolor = gmap->state->get_texture_manager()->Load("boxColor.bmp");
        boxNormal= gmap->state->get_texture_manager()->Load("box.bmp");
       texture=boxNormal;
        layer = ObjectLayerForeground;
 }
 /*
 boxColor::boxColor(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("boxColor.bmp");
        layer = ObjectLayerForeground;
 }*/

 destination::destination(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("destination.png");
        layer = ObjectLayerBackground;
 }

 wall::wall(GameMap *state_) :object(state_){
        texture = gmap->state->get_texture_manager()->Load("wall.bmp");
        layer = ObjectLayerForeground;
 }
