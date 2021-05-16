
#include "gamestate.hpp"
#include "menu_scene.hpp"
#include "size.hpp"

void StartButton::Execute() {
   GameState *state = scene->GetState();
   state->currentScene = state->gameScene;

   if (!state->saveLoadedFirst) {
        state->gameScene->Load();
        state->saveLoadedFirst = true;
   }
}

void LevelSelectButton::Execute() {
}


MenuScene::MenuScene(GameState *state_)
    : Scene(state_)
    , startBtn(state_, this)
    ,selectBtn(state_,this){
        // thay bag startBtn voi selectBtn
    backgroundimg = state->get_texture_manager()->Load("background.bmp");
    startBtn.SetSize({ 140, 70 });
    startBtn.SetPosition({ (SCREENSIZE_X - 140)/2, (SCREENSIZE_Y-70)/2 });
    selectBtn.SetSize({ 140, 70 });
    selectBtn.SetPosition({ (SCREENSIZE_X - 140)/2, (SCREENSIZE_Y-70)/2 +100});

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
     SDL_Rect dest_rect;

    dest_rect.x = 0;
    dest_rect.y = 0;
    dest_rect.w = SCREENSIZE_X;
    dest_rect.h = SCREENSIZE_Y;

    SDL_RenderCopy(state->get_renderer(), backgroundimg, NULL, &dest_rect);
    startBtn.Draw();
    selectBtn.Draw();
}
