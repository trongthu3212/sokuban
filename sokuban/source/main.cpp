#include <SDL2/SDL.h>
#include <iostream>

#include "resman.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    TextureManager manager(renderer);

    SDL_Texture *texture = manager.Load("castle.bmp");

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }

        //SDL_Rect dstrect = { 5, 5, 320, 240 };
        //SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    manager.Unload(texture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
