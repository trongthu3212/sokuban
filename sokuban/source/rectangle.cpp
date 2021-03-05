#include "rectangle.hpp"

vec2d rectangle::bottom_right()
    {
         return vec2d(top_left.x + sizes.x, top_left.y + sizes.y);
    }

