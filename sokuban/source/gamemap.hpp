#include "gamestate.hpp"
#include "object.hpp"
#include <fstream>
#include <string>
struct GameMap{
    object* objs[200][200];
    GameState * state;
    GameMap(GameState* state_) {
        state = state_ ;
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
                   objs[i][line]=new wall;
                    break;
                case '0':
                    // Them object Box vao mang
                    objs[i][line]=new box;

                    break;
                case 'x':
                    // Them nguoi choi vao mang
                    objs[i][line]=new player;
                    break;
                default:
                    break;

            }
        }
    }
    }
};
