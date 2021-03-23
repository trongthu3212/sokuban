#pragma once

#include <sdl2/sdl.h>
#include "vec2d.hpp"

struct GameMap;

struct object
{
public:
    object(GameMap *state_);



    virtual ~object() ;
    vec2d get_pos();
    void set_pos(int x, int y){
       pos.x=x;//same vec2d(x,y);
        pos.y=y;
     }
    virtual void OnKeyPress(int key_code) {
    }

    virtual void Draw();

    void SetMoved(const bool moved_) {
        moved = moved_;
    }
protected:
    bool moved;

    GameMap *state;
    SDL_Texture *texture;

    vec2d pos;
};

struct player: public object
 {
public:
    player(GameMap *state_);

    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override;
};

struct box: public object
{
public:
    box(GameMap *state_);

    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override{
    }
};

struct wall: public object
{
public:
    wall(GameMap *state_);
    //override OnKeyPress va viet thuat toan di chuyen cho wall
    void OnKeyPress(int key_code) override{
    }
};
struct destination: public object
{
    destination(GameMap *state_);
};
