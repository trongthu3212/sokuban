#pragma once

#include "vec2d.hpp"

const int KEY_DOWN = 1;
const int KEY_UP = 2;
const int KEY_LEFT = 3;
const int KEY_RIGHT = 4;

struct object{
public:
    vec2d get_pos();

    virtual void OnKeyPress(int key_code) {
    }
protected:
    vec2d pos;
};

struct player: public object {
public:
    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override;
};

struct box: public object{
public:
    //override OnKeyPress va viet thuat toan di chuyen cho Player
    void OnKeyPress(int key_code) override{
    }
};

struct wall: public object{
public:
    //override OnKeyPress va viet thuat toan di chuyen cho wall
    void OnKeyPress(int key_code) override{
    }
};
