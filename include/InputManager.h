#pragma once

#include "../include/Keys.h"

namespace TGA
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		bool keyDown(Keys key);

		Uint32 timeHeld(Keys key);

		void update();

	private:
		std::map<int, char> m_Keystates;
	};
}