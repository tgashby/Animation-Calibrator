#pragma once

#include "../include/Keys.h"

namespace TGA
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		// Determine if a given key is down
		bool keyDown(Keys key);

		// Determine how long a given key has been down
		Uint32 timeHeld(Keys key);

		// Update the timers and key states
		void update();

	private:
		std::map<int, char> m_Keystates;
	};
}