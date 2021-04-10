#include "gamescene.hpp"
#include "gamemap.hpp"

GameScene::GameScene(GameState *state_)
    : Scene(state_) {
    gmap = new GameMap(state_);
    gmap->load("map.txt");
}

GameScene::~GameScene() {
    delete gmap;
}

void GameScene::Update(const SDL_Event &event) {
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
