#define SDL_MAIN_HANDLED

#include <iostream>
#include "WindowSDL.h"
#include "WindowRaylib.h"

int main()
{
    Window* win = new WindowRaylib();

    win->CreateWindow("test", 600, 600);

    Sprite* s = new Sprite();

    s->LoadSprite();
    s->SetPosition();

    while (win->IsOpen()) {
        win->Clear();

        win->DrawSprite();
    }

    return 0;
}