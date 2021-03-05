#pragma once

#include <SDL2/SDL.h>

#include <map>
#include <string>

struct TextureInfo {
    uint32_t useCount;
    SDL_Texture *tex;
    SDL_Surface *surf;
};

class TextureManager {
private:
    std::map<std::string, TextureInfo> texs;
    SDL_Renderer *renderer;

public:
    TextureManager(SDL_Renderer *renderer_) : renderer(renderer_) {}
    ~TextureManager();

    SDL_Texture *Load(std::string path);
    void Unload(SDL_Texture *tex);
};
