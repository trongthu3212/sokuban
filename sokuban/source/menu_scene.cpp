
#include "gamestate.hpp"
#include "menu_scene.hpp"

void StartButton::Execute() {
   GameState *state = scene->GetState();
   state->currentScene = state->gameScene;
}

void LevelSelectButton::Execute() {
}


MenuScene::MenuScene(GameState *state_)
    : Scene(state_)
    , startBtn(state_, this)
    ,selectBtn(state_,this){
        // thay bag startBtn voi selectBtn
    startBtn.SetSize({200, 100});
    startBtn.SetPosition({ 0, 0 });
    selectBtn.SetSize({ 200, 100 });
    selectBtn.SetPosition({ 300, 300 });

}

MenuScene::~MenuScene() {
}
void MenuScene::Update(const SDL_Event &event) {
    switch( event.type ){
    case SDL_KEYDOWN:
    {
        break;
    }
    case SDL_MOUSEBUTTONDOWN:{
        int x,y;
        SDL_GetMouseState(&x, &y);

        //restartBtn.OnMousePressed(event.button.button, x, y);
        // goi ham OnMousePressed cung tham so cua 2 bien bbtn
        startBtn.OnMousePressed(event.button.button, x, y);
        selectBtn.OnMousePressed(event.button.button, x, y);
        break;
    }

    case SDL_KEYUP:
        //sprintf( "Up\n" );
        break;


    default:
        break;
    }
}

void MenuScene::Draw() {
    // ve 2
    startBtn.Draw();
    selectBtn.Draw();
}
