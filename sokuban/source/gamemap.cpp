#include "gamemap.hpp"
#include  "gamestate.hpp"
#include "size.hpp"
#include <cmath>
 GameMap::GameMap(GameState* state_) {
        state = state_ ;

        memset(background, 0, sizeof(background));
        memset(foreground, 0, sizeof(foreground));

        ground = state->get_texture_manager()->Load("ground.bmp");


}
GameMap::~GameMap(){
        for(int i=0;i<width;i++){
            for(int j=0;j<width;j++){
                if(background[i][j]!=NULL){
                    delete background[i][j];
                }
                if(foreground[i][j]!=NULL){
                    delete foreground[i][j];
                }
            }
        }

        state->get_texture_manager()->Unload(ground);
}
void GameMap::draw()
    {
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                SDL_Rect dest_rect;

                dest_rect.x = start_pos.x + i*boxsize;
                dest_rect.y = start_pos.y + j*boxsize;
                dest_rect.w = boxsize;
                dest_rect.h = boxsize;

                SDL_RenderCopy(state->get_renderer(), ground, NULL, &dest_rect);
                if(background[i][j] != NULL){
                    background[i][j]->Draw();
                }

                if(foreground[i][j] != NULL) {
                    foreground[i][j]->Draw();
                }

            }
        }

    }
void GameMap::load(std::string path){
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
                        boxquantites ++;
                        break;
                    case 'x':
                        // Them nguoi choi vao mang
                        foreground[i][line] = new player(this);
                        foreground[i][line]->set_pos(i, line);

                        control = (player*)foreground[i][line];
                        break;
                    case 'y':
                        point++;

                        background[i][line] = new destination(this);
                        background[i][line]->set_pos(i, line);
                    default:
                        break;

                }
            }
            width = std::max(len,line);
        }
        height=line+1;

        int average_boxsize = std::min(std::round((float)SCREENSIZE_X/width),std::round((float)SCREENSIZE_Y/height));
        if(average_boxsize>=63) boxsize=64;
       else if(average_boxsize>=31)boxsize=32;
       else boxsize=16;

        start_pos.x = (SCREENSIZE_X - (boxsize * width))/2;
        start_pos.y = (SCREENSIZE_Y- (boxsize * height))/2;
    }
