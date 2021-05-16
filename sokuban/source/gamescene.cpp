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
    scene->Save();
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
    scene->Save();
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

void GameScene::Save() {
    std::ofstream savefile("savemap.txt");
    savefile << level << std::endl ;
    savefile << gmap->control->get_pos().x << " "<< gmap->control->get_pos().y << std::endl;
    savefile << gmap->boxquantites << std::endl;
    int dem =0;
     for(int i=0;i<gmap->width;i++)
    {
            for(int j=0;j<gmap->height;j++)
        {
                if(gmap->foreground[i][j]!=NULL)
            {
                    if ( gmap->foreground[i][j]->GetObjectType() == ObjectTypeBox )
                        {
                            savefile << i << " "<< j <<std::endl;
                            dem++;
                        }
                if(dem == gmap->boxquantites)
                    {break;}


            }
        }
    }
    savefile.close();
}

void GameScene::Load() {
    std::ifstream loadfile("savemap.txt");
    if (!loadfile.good()) {
        return;
    }
    loadfile >> level;

    int x, y;

    SwitchMap();
    loadfile >> x >> y;

    vec2d prevpos = gmap->control->get_pos();

    gmap->control->set_pos(x, y);
    gmap->foreground[prevpos.x][prevpos.y] = nullptr;
    gmap->foreground[x][y] = gmap->control;

    int boxcount = 0;
    int dem = 0;
    loadfile >> boxcount;

     for(int i=0;i<gmap->width;i++)
    {
            for(int j=0;j<gmap->height;j++)
        {
                if(gmap->foreground[i][j]!=NULL)
            {
                    if ( gmap->foreground[i][j]->GetObjectType() == ObjectTypeBox )
                        {
                            delete gmap->foreground[i][j];
                            gmap->foreground[i][j] = nullptr;
                            dem++;
                        }


                if(dem == boxcount)
                    {break;}


            }
        }
    }

    gmap->pointChecked = 0;

    for (int i = 0; i < boxcount; i++) {
        int x, y;
        loadfile >> x >> y;

        gmap->foreground[x][y] = new box(gmap);
        gmap->foreground[x][y]->set_pos(x, y);

        if (gmap->background[x][y] && (gmap->background[x][y]->GetObjectType() == ObjectTypeDestination)) {
            gmap->pointChecked++;
        }
    }

    loadfile.close();
}
