#pragma once
#include "object.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <SDL2/SDL.h>
#include "vec2d.hpp"
struct GameState;
struct GameMap{
    object* background[200][200]; // mang cho cac object nam o lop nen
    object* foreground[200][200]; // mang cho cac object nam o foreground

    player *control; //  object tuong trung cho player

   SDL_Texture* ground; // la anh tuong trung cho 1 o nen

    GameState * state;
    GameMap(GameState* state_);

    int height; // chieu dai cua map
    int width; // chieu rong cua map

    int point=0; // tong so diem dich
    int pointChecked = 0; // so dich ma den ma hop da duoc dat vao


    ~GameMap();
    void draw(); // ve
    void load(std::string path);// tai thong tin ve map tu 1 tep

    vec2d start_pos; // vi tri cua map tren man hinh
    int boxsize;  // do to cua 1 o
    int boxquantites = 0; //  so luong box duoc dem khi save
};
