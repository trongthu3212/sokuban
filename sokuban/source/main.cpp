#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argv, char** args) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
       cout << "Endl Init Failed." << endl;
       return 1;
    }

   cout << "SDL Init succeeded." << endl;

   SDL_Quit();
   return 0;
}
