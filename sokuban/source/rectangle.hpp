#pragma once

#include "vec2d.hpp"
// bieu thi hinh chu nhat trong toa do khong gian 2 chieu
struct rectangle{
public:
    vec2d bottom_right();// vi tri goc ben phai duoi cung
protected:
    vec2d top_left; // vi tri goc ben trai tren
    vec2d sizes; // kich co cua hinh chu nhat
};
