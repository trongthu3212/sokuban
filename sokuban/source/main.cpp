#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include "gamemap.hpp"
#include "gamestate.hpp"

int main(int argc, char ** argv)
{
    GameState state;
    state.loop();

    return 0;
}
