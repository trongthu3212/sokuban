#include "object.hpp"

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
