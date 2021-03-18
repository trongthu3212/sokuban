#pragma once

#include <sdl2/sdl.h>
#include "vec2d.hpp"

struct GameState;

struct object{
public:
    object(GameState *state_);



    ~object() ;
    vec2d get_pos();
    void set_pos(int x, int y){
       pos.x=x;//same vec2d(x,y);
        pos.y=y;
     }
    virtual void OnKeyPress(int key_code) {
    }

    virtual void Draw();
protected:
    GameState *state;
    SDL_Texture *texture;

    vec2d pos;
};

struct player: public object {
public:
    player(GameState *state_) :object(state_){

    }


    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override;
};

struct box: public object{
public:
    box(GameState *state_) :object(state_){

    }

    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override{
    }
};

struct wall: public object{
public:
    wall(GameState *state_) :object(state_){

    }
    //override OnKeyPress va viet thuat toan di chuyen cho wall
    void OnKeyPress(int key_code) override{
    }
};
