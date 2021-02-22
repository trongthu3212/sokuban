#include "resman.hpp"

TextureManager::~TextureManager() {
    for (std::map<std::string, TextureInfo>::iterator ite = texs.begin(); ite != texs.end(); ite++) {
        SDL_DestroyTexture(ite->second.tex);
        SDL_FreeSurface(ite->second.surf);
    }
}

SDL_Texture *TextureManager::Load(std::string path) {
    std::map<std::string, TextureInfo>::iterator ite = texs.find(path);
    if (ite == texs.end()) {
        // Load it
        TextureInfo info;
        info.surf = SDL_LoadBMP(path.c_str());
        info.tex = SDL_CreateTextureFromSurface(renderer, info.surf);
        info.useCount = 1;

        SDL_Texture *retResult = info.tex;

        texs.emplace(path, info);
        return retResult;
    }

    TextureInfo &info = ite->second;
    info.useCount++;

    return info.tex;
}

void TextureManager::Unload(SDL_Texture *tex) {
    for (std::map<std::string, TextureInfo>::iterator ite = texs.begin(); ite != texs.end(); ite++) {
        if (ite->second.tex == tex) {
            ite->second.useCount--;

            if (ite->second.useCount == 0) {
                SDL_DestroyTexture(ite->second.tex);
                SDL_FreeSurface(ite->second.surf);

                texs.erase(ite);
                break;
            }
        }
    }
}
