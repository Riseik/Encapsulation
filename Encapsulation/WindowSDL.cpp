#include "WindowSDL.h"

void WindowSDL::CreateWindow(const char* name, int height, int width)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Init();
	InitVariable();
}

void WindowSDL::Clear()
{
	SDL_FreeSurface(textSurface);
	SDL_RenderClear(render);
}

bool WindowSDL::IsOpen()
{
	return window;
}

void WindowSDL::Draw(std::vector<Sprite*> s)
{
	frameStart = SDL_GetTicks();

//	spritePos = { (int)s->GetBall()->pos.x, (int)s->GetBall()->pos.y, (int)(((SDL_Surface*)s->GetSurface())->h * SPRITE_SCALE), (int)(((SDL_Surface*)s->GetSurface())->w * SPRITE_SCALE)};
//	SDL_SetRenderDrawColor(render, 130, 130, 130, 255);
//	SDL_RenderCopy(render, (SDL_Texture*)s->GetData(), NULL, &spritePos);

	fps = std::to_string(CalculFps(frameStart));
	
	DisplayText(("fps  counter  :  " + fps).c_str());
	SDL_RenderCopy(render, textTexture, NULL, &fpsPos);
	
	DisplayText("'SPACE'  to  switch  to  Raylib");
	SDL_RenderCopy(render, textTexture, NULL, &textPos);
	
	SDL_RenderPresent(render);
	SDL_UpdateWindowSurface(window);

	SDL_Delay(50);

}


int WindowSDL::CalculFps(Uint32 Start)
{
	int frameTime = SDL_GetTicks() - Start;
	if (Start > frameTime) {
		SDL_Delay(frameDelay - frameTime);
		return FPS_CAP;
	}
	else {
		return frameTime != 0 ? 1000 / frameTime : 0;
	}
}


bool WindowSDL::Event()
{
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_SPACE)
			{
				printf("Barre d'espace appuyée!\n");
				return true;
			}
		}
		if (event.type == SDL_WINDOWEVENT)
		{
			switch (event.window.event) {

			case SDL_WINDOWEVENT_CLOSE:
				open = false;
				DestroyWindow();
				break;

			default:
				break;
			}
		}
	}
}

void WindowSDL::DestroyWindow()
{
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool WindowSDL::CheckCloseWindow()
{
	return open;
}


void WindowSDL::InitVariable()
{
	font = TTF_OpenFont("../Daydream.ttf", 24);
	fpsPos = { FPS_TEXT_POSITION_X, FPS_TEXT_POSITION_Y, FPS_COUNTER_SDL_TEXT_WIDTH, SDL_FONT_HEIGHT };
	textPos = { FPS_TEXT_POSITION_X, FPS_TEXT_POSITION_Y + 550, FPS_COUNTER_SDL_TEXT_WIDTH + 100, SDL_FONT_HEIGHT };
}

void WindowSDL::DisplayText(const char* text)
{
	textSurface = TTF_RenderText_Solid(font, text, fontColor);
	textTexture = SDL_CreateTextureFromSurface(render, textSurface);
}

Sprite* WindowSDL::CreateSprite()
{
	return new SpriteSDL;
}
