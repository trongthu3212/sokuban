#include "gamescene.hpp"
#include "gamestate.hpp"
#include "gamemap.hpp"

#include <sstream>

void RestartButton::Draw() {
    SDL_Rect dest_rect;

    dest_rect.x = 0;
    dest_rect.y = 0;//gmap->start_pos.y + pos.y*gmap->boxsize;
    dest_rect.w = 300;
    dest_rect.h = 150;

    SDL_RenderCopy(state->get_renderer(), img, NULL, &dest_rect);
}

void RestartButton::Execute() {
    scene->SwitchMap();
}

GameScene::GameScene(GameState *state_)
    : Scene(state_)
    , restartBtn(state_, this) {
    gmap = new GameMap(state_);
    gmap->load("map1.txt");
}

GameScene::~GameScene() {
    delete gmap;
}
void GameScene::SwitchMap(){
    delete gmap;

    std::stringstream ss;
    ss << level;
    std::string xaulevel = ss.str();

    gmap = new GameMap(state);
    gmap->load("map" + xaulevel+".txt");
}
void GameScene::Update(const SDL_Event &event) {
    if(gmap->point==gmap->pointChecked){
       level=level+1;
       SwitchMap();
    }

    switch( event.type ){
    case SDL_KEYDOWN:
    {
        if(event.key.keysym.sym==SDLK_r){
            SwitchMap();
        } else {
            gmap->control->OnKeyPress(event.key.keysym.sym);
        }
        break;
    }
    case SDL_MOUSEBUTTONDOWN:{
        int x,y;
        SDL_GetMouseState(&x, &y);
        if((x<300 && y <150) &&(x>0 && y>0)){
            restartBtn.Execute();
        }

    }

    case SDL_KEYUP:
        //sprintf( "Up\n" );
        break;


    default:
        break;
    }
}

void GameScene::Draw() {
    gmap->draw();
    restartBtn.Draw();
}
