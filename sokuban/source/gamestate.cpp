#include "gamestate.hpp"
#include <fstream>

GameState::GameState() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Sokuban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    manager = TextureManager(renderer);
}

GameState::~GameState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

SDL_Renderer *GameState::get_renderer() {
    return renderer;
}

TextureManager *GameState::get_texture_manager() {
    return &manager;
}

void GameState::loop() {
    SDL_Texture *texture = manager.Load("castle.bmp");
    SDL_Event event;

    bool quit = false;

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }

        std::string s;
        std::ifstream file_map("map.txt");

        int line=-1;

        while (file_map.good()){
            getline(file_map,s);
            line++;
            int len;
            len = s.length();
            for(int i=0;i<len;i++){
                SDL_Rect dstrect = { i * 32,line * 32, 32, 32 };
                switch(s[i]){
                case '#':
                    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
                    break;
                /*case '0':
                    SDL_RenderCopy(renderer, textu, NULL, &dstrect);
                    break;*/
                default:
                    //cout<<" ";
                    break;
                }
            }
        }

        SDL_RenderPresent(renderer);
    }

    manager.Unload(texture);
}
