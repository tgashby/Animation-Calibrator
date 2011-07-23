#include "../include/InputManager.h"

namespace TGA
{
	InputManager::InputManager() {}

	InputManager::~InputManager() {}

	bool InputManager::keyDown(Key key)
	{
		return keystates.at(key);
	}

	void InputManager::update()
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_KEYDOWN:
				keystates[event.key.keysym.sym] = true;
				break;

			case SDL_KEYUP:
				keystates[event.key.keysym.sym] = false;
				break;

			case SDL_MOUSEBUTTONUP:
				SDL_GetMouseState(&mouseX, &mouseY);
			}
		}
	}

	SDL_Point InputManager::getMouseCoords()
	{
		SDL_Point pt;
		pt.x = mouseX;
		pt.y = mouseY;

		return pt;
	}
};