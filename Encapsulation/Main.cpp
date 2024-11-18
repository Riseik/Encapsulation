#include <iostream>
#include "WindowSDL.h"

int main()
{
    Window* win = new WindowSDL();

    Sprite* s = new Sprite();

    s->LoadSprite();
    s->SetPosition();

    while (win->IsOpen()) {
        win->Clear();

        win->DrawSprite();
    }

    std::cout << "Hello World!\n";
}