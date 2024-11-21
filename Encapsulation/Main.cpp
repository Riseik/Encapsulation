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

    bool RaylibSwitch = false;
    win = new WindowSDL();
    const char* title = "";

    while (true)
    {
        (RaylibSwitch) ? title = "Encapsulation Raylib" : title = "Encapsulation SDL";
        win->CreateWindow(title, WINDOW_HEIGHT, WINDOW_WIDTH);

        Sprite* s = win->CreateSprite();

        s->LoadSprite(IMAGE_PATH);
        s->SetRad();
        s->SetPosition(std::rand() % WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT);
        s->SetSpeed((float)(std::rand() % (MAX_BALL_SPEED - MIN_BALL_SPEED) + MIN_BALL_SPEED) / 100, (float)(std::rand() % (MAX_BALL_SPEED - MIN_BALL_SPEED) + MIN_BALL_SPEED) / 100);


        while (win->IsOpen()) {
            win->Clear();
            s->Move();
            win->Draw(s);
            if (win->Event())
            {
                if (RaylibSwitch)
                {
                    win->DestroyWindow();
                    win = new WindowSDL();
                    RaylibSwitch = false;
                }
                else
                {
                    win->DestroyWindow();
                    win = new WindowRaylib();
                    RaylibSwitch = true;
                }
            }

        }
    }


    return 0;
}