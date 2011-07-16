#include "../include/InputManager.h"

namespace TGA
{
	InputManager::InputManager() {}

	InputManager::~InputManager() {}

	bool InputManager::keyDown(Key key)
	{
		// Return the keystate of the desired key
	}

	void InputManager::update()
	{
		// Create an SDL_Event

		// WHILE there are still events to process

			// SWITCH based on the event

				// CASE keydown
				
					// Set the keystate to true

				// CASE keyup
			
					// Set the keystate to false

				// CASE mouseClick

					// Update mouse coords

			// ENDSWITCH

		// ENDWHILE
	}

	SDL_Point InputManager::getMouseCoords()
	{
		// Return an SDL_Point made of mouse coordinates
	}
};