#define SDL_MAIN_HANDLED

#include <iostream>
#include "WindowSDL.h"
#include "WindowRaylib.h"
#include "SpriteRaylib.h"

int main()
{
    Window* win = new WindowRaylib();

    win->CreateWindow("test", WINDOW_HEIGHT, WINDOW_WIDTH);

    Sprite* s = win->CreateSprite();

    s->LoadSprite(IMAGE_PATH);
    s->SetRad();
    s->SetPosition(GetRandomValue(0, WINDOW_WIDTH), GetRandomValue(0, WINDOW_HEIGHT));
    s->SetSpeed((float)GetRandomValue(MIN_BALL_SPEED, MAX_BALL_SPEED) / 100, (float)GetRandomValue(MIN_BALL_SPEED, MAX_BALL_SPEED) / 100);


    while (win->IsOpen()) {
        win->Clear();
        s->Move();
        win->DrawSprite(s);
    }

    return 0;
}