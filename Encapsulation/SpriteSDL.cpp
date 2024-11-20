#include "SpriteSDL.h"

void SpriteSDL::LoadSprite(std::string path)
{
	tmpSurface = SDL_LoadBMP("../Logo_SCP_Foundation.bmp");
	if (tmpSurface == NULL)
	{
		std::cout << "erreur";
	}

}
