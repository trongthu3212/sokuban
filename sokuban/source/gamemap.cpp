#include "gamemap.hpp"
#include  "gamestate.hpp"
 GameMap::GameMap(GameState* state_) {
        state = state_ ;

        memset(background, 0, sizeof(background));
        memset(foreground, 0, sizeof(foreground));

        ground = state->get_texture_manager()->Load("ground.bmp");
}

void GameMap::draw()
    {
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                SDL_Rect dest_rect;

                dest_rect.x = i*32;
                dest_rect.y = j*32;
                dest_rect.w = 32;
                dest_rect.h = 32;

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
    }
