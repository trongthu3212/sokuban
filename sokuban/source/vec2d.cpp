#include "vec2d.hpp"
#include <cmath>
float vec2d::length(){
    return sqrt(x*x + y*y);
}
vec2d vec2d::operator + (vec2d vephai){
        return vec2d(x + vephai.x, y + vephai.y);
    }
vec2d vec2d::operator - (vec2d vephai){
        return vec2d(x - vephai.x, y + vephai.y);
    }



