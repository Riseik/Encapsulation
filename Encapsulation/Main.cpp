#define SDL_MAIN_HANDLED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "WindowSDL.h"
#include "WindowRaylib.h"
#include "SpriteRaylib.h"

Window* win;

int main()
{
    srand(time(0));


    win = new WindowSDL();

    win->CreateWindow("test", WINDOW_HEIGHT, WINDOW_WIDTH);

    Sprite* s = win->CreateSprite();

    s->LoadSprite(IMAGE_PATH);
    s->SetRad();
    s->SetPosition(std::rand() % WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT);
    s->SetSpeed((float)(std::rand() % (MAX_BALL_SPEED - MIN_BALL_SPEED) + MIN_BALL_SPEED) / 100, (float)(std::rand() % (MAX_BALL_SPEED - MIN_BALL_SPEED) + MIN_BALL_SPEED) / 100);


    while (win->IsOpen()) {
        win->Clear();
        if (IsKeyPressed(KEY_ENTER)) win->CreateSprite();
        s->Move();
        win->Draw(s);
    }

    return 0;
}