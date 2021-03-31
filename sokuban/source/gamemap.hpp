#pragma once
#include "object.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
struct GameState;
struct GameMap{
    object* background[200][200];
    object* foreground[200][200];

    player *control;

    GameState * state;
    GameMap(GameState* state_) {
        state = state_ ;

        memset(background, 0, sizeof(background));
        memset(foreground, 0, sizeof(foreground));
    }

    int height;
    int width;
    void advance(object *obj, const vec2d &amount) {
    }
    void draw() {
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                if(background[i][j] != NULL){
                    background[i][j]->Draw();
                }

                if(foreground[i][j] != NULL) {
                    foreground[i][j]->Draw();
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
                        foreground[i][line] = new wall(this);
                        foreground[i][line]->set_pos(i, line);
                        break;
                    case '0':
                        // Them object Box vao mang
                        foreground[i][line] = new box(this);
                        foreground[i][line]->set_pos(i, line);
                        break;
                    case 'x':
                        // Them nguoi choi vao mang
                        foreground[i][line] = new player(this);
                        foreground[i][line]->set_pos(i, line);

                        control = (player*)foreground[i][line];
                        break;
                    case 'y':
                        background[i][line] = new destination(this);
                        background[i][line]->set_pos(i, line);
                    default:
                        break;

                }
            }
            width = std::max(len,line);
        }
        height=line;
    }
};
