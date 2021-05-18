#pragma once

#include <SDL2/SDL.h>

#include <map>
#include <string>

struct TextureInfo {
    uint32_t useCount;
    SDL_Texture *tex;
};

// Quản lý việc sử dụng các ảnh trong trò chơi
class TextureManager {
private:
    std::map<std::string, TextureInfo> texs;
    SDL_Renderer *renderer;

public:
    TextureManager() {}
    TextureManager(SDL_Renderer *renderer_) : renderer(renderer_) {}

    ~TextureManager();

    // Tải một ảnh mới, có thể kiểm tra những ảnh đã tải để không tốn thêm công sức tải lại
    SDL_Texture *Load(std::string path);

    // Bỏ tải một ảnh trước đó.
    void Unload(SDL_Texture *tex);
};
