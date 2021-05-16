#pragma once

struct vec2d {
    int x,y;

    vec2d (int x_, int y_){
        x=x_;
        y=y_;
    }
     vec2d (){
        x=0;
        y=0;
    }


    float length();
    vec2d operator + (vec2d vephai);
    vec2d operator - (vec2d vephai);

};
