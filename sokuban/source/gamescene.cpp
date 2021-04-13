#include "gamescene.hpp"
#include "gamemap.hpp"

#include <sstream>

GameScene::GameScene(GameState *state_)
    : Scene(state_) {
    gmap = new GameMap(state_);
    gmap->load("map1.txt");
}

GameScene::~GameScene() {
    delete gmap;
}

void GameScene::Update(const SDL_Event &event) {
    if(gmap->point==gmap->pointChecked){
        delete gmap;
       level=level+1;

        std::stringstream ss;
        ss << level;
        std::string xaulevel = ss.str();

        gmap = new GameMap(state);
        gmap->load("map" + xaulevel+".txt");
    }

    switch( event.type ){
    case SDL_KEYDOWN:
    {
        gmap->control->OnKeyPress(event.key.keysym.sym);
        break;
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
}
