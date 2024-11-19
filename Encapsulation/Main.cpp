#define SDL_MAIN_HANDLED

#include <iostream>
#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
    Window* win = new WindowSDL();

    win->CreateWindow("test", 600, 600);

    Sprite* s = new Sprite();

    s->LoadSprite();
    s->SetRad();
    s->SetPosition(std::rand() % 601, std::rand() % 601);


    while (win->IsOpen()) {
        win->Clear();
        win->DrawSprite(s);
    }

    return 0;
}