#pragma once

#include <sdl2/sdl.h>
#include "vec2d.hpp"

struct GameMap;

enum ObjectLayer {
    ObjectLayerBackground = 0,
    ObjectLayerForeground = 1
};

enum ObjectType {
    ObjectTypeUndefined = 0,
    ObjectTypeWall = 1,
    ObjectTypeBox = 2,
    ObjectTypePlayer = 3,
    ObjectTypeDestination = 4
};

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

    virtual void OnMousePress(int mouse_code){
    }

    virtual void Draw();

    virtual bool Move(vec2d amount);

    virtual ObjectType GetObjectType() {
        return ObjectTypeUndefined;
    }

protected:
    GameMap *gmap;
    SDL_Texture *texture;

    ObjectLayer layer;

    vec2d pos;
};

struct player: public object
 {
public:
    player(GameMap *state_);

    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override;
    friend class SaveButton;

    ObjectType GetObjectType() override{
        return ObjectTypePlayer;
    }
};

struct box: public object
{
private:
     SDL_Texture*boxcolor;
     SDL_Texture*boxNormal;

public:
    box(GameMap *state_);
    ~box() override;

    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override{
    }

    bool Move(vec2d amount) override;

    ObjectType GetObjectType() override{
        return ObjectTypeBox;
    }
};


struct wall: public object
{
public:
    wall(GameMap *state_);
    //override OnKeyPress va viet thuat toan di chuyen cho wall
    void OnKeyPress(int key_code) override{
    }

    virtual bool Move(vec2d amount) {
        return false;
    }

    ObjectType GetObjectType() override{
        return ObjectTypeWall;
    }
};
struct destination: public object
{
    destination(GameMap *state_);

    ObjectType GetObjectType() override{
        return ObjectTypeDestination;
    }
};
