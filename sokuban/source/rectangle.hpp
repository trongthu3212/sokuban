#pragma once

#include "vec2d.hpp"

struct rectangle{
public:
    vec2d bottom_right();
protected:
    vec2d top_left;
    vec2d sizes;
};
