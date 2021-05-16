#include "gamescene.hpp"
#include "gamestate.hpp"
#include "gamemap.hpp"
#include "size.hpp"
#include "object.hpp"

#include <sstream>
#include<fstream>
#include<cmath>

void RestartButton::Execute() {
    scene->SwitchMap();
}

void HomeButton::Execute() {
    scene->GetState()->currentScene = scene->GetState()->menuScene;
}

GameScene::GameScene(GameState *state_)
    : Scene(state_)
    , restartBtn(state_, this)
    , homeBtn(state_, this)
    , saveBtn (state_, this) {
    gmap = new GameMap(state_);
    gmap->load("map1.txt");

    restartBtn.SetSize({50, 50});
    restartBtn.SetPosition({ 10, 10 });

    homeBtn.SetSize({ 50, 50 });
    homeBtn.SetPosition({ 70, 10 });

    saveBtn.SetSize({50,50});
    saveBtn.SetPosition({130,10});

}

void SaveButton::Execute()
{
   std::ofstream savefile("savemap.txt");
    savefile << scene->gmap->control->pos.x << " "<<scene->gmap->control->pos.y << std::endl;
    savefile << scene->gmap->boxquantites << std::endl;
    savefile << scene->level << std::endl ;
    int dem =0;
     for(int i=0;i<scene->gmap->width;i++)
    {
            for(int j=0;j<scene->gmap->height;j++)
        {
                if(scene->gmap->foreground[i][j]!=NULL)
            {
                    object::GetObjectType ;
                    if ( scene->gmap->foreground[i][j]->GetObjectType() == ObjectTypeBox )
                        {
                            savefile << i << " "<< j <<std::endl;
                            dem++;
                        }
                if(dem == scene->gmap->boxquantites)
                    {break;}


            }
        }
    }
    savefile.close();
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

        restartBtn.OnMousePressed(event.button.button, x, y);
        homeBtn.OnMousePressed(event.button.button, x, y);
        saveBtn.OnMousePressed(event.button.button, x, y);
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
    restartBtn.Draw();
    homeBtn.Draw();
    saveBtn.Draw();
}


