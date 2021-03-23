#pragma once
#include "object.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
struct GameState;
struct GameMap{
    std::vector<object*> objs[200][200];

    GameState * state;
    GameMap(GameState* state_) {
        state = state_ ;
        memset(objs, 0, sizeof(objs));
    }

    int height;
    int width;
    void draw() {
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                if(!objs[i][j].empty()){
                    for(int k=0;k<objs[i][j].size();k++){
                        objs[i][j][k]->Draw();

                    }
                }
            }
        }

    }
    void load(std::string path){
    std::ifstream file_map;
    file_map.open(path);
    std::string s;
    int line=-1;

    while (file_map.good()){
        getline(file_map,s);
        line++;
        int len;
        len = s.length();

        for(int i=0;i<len;i++){
            switch(s[i]){
                case '#':
                   objs[i][line].push_back(new wall(this));
                    break;
                case '0':
                    // Them object Box vao mang
                    objs[i][line].push_back(new box(this));

                    break;
                case 'x':
                    // Them nguoi choi vao mang
                    objs[i][line].push_back(new player(this));
                    break;
                case 'y':
                    objs[i][line].push_back(new destination(this));
                default:
                    break;

            }
            if(!objs[i][line].empty()){
                for(int k=0;k<objs[i][line].size();k++){
                    objs[i][line][k]->set_pos(i,line);

                }
            }
        }
            width = std::max(len,line);
    }
            height=line;
    }
};
