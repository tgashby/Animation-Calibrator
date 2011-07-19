#include "../include/InputManager.h"

namespace TGA
{
	InputManager::InputManager() {}

	InputManager::~InputManager() {}

	bool InputManager::keyDown(Key key)
	{
		// Return the keystate of the desired key
		return keystates.at(key);
	}

	void InputManager::update()
	{
		// Create an SDL_Event
		SDL_Event event;

		// WHILE there are still events to process
		while(SDL_PollEvent(&event))
		{
			// SWITCH based on the event
			switch(event.type)
			{
				// CASE keydown
			case SDL_KEYDOWN:
				// Set the keystate to true
				keystates[event.key.keysym.sym] = true;
				break;

				// CASE keyup
			case SDL_KEYUP:
				// Set the keystate to false
				keystates[event.key.keysym.sym] = false;
				break;

				// CASE mouseClick
			case SDL_MOUSEBUTTONUP:
				// Update mouse coords
				SDL_GetMouseState(&mouseX, &mouseY);
			}
			// ENDSWITCH
		}
		// ENDWHILE
	}

	SDL_Point InputManager::getMouseCoords()
	{
		SDL_Point pt;
		pt.x = mouseX;
		pt.y = mouseY;

		// Return an SDL_Point made of mouse coordinates
		return pt;
	}
};