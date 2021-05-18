#pragma once

#include <SDL2/SDL.h>
#include "object.hpp"
#include "vec2d.hpp"
#include <string>

struct GameState;

// Biểu hiện nút nhấn trong chương trình
class Button {
protected:
    // Ảnh tương ứng với nút nhấn
    SDL_Texture*img;
    GameState*state;

    // Vị trí nút nhấn trên màn hình
    vec2d position;

    // Độ lớn nút nhấn trên màn hình
    vec2d btnsize;

public:
    Button(GameState *state_,std::string path);

    // Đặt độ dài rộng của nút nhấn
    void SetSize(const vec2d &size);

    // Đặt vị trí của nút nhấn trên màn hình, theo bên trái trên cùng
    void SetPosition(const vec2d &pos);

    // Vẽ nút ra màn hình
    virtual void Draw();

    // Thực hiện chức năng của nút
    virtual void Execute() {}

    // Xử lý nút khi chuột được nhấn vào nó.
    virtual void OnMousePressed(const int btn, const int mouseX, const int mouseY);
};
