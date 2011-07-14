#pragma once

#include "../include/Texture.h"

namespace TGA
{
	class TextureManager
	{
	public:
		// Constructors/Destructor
		TextureManager();
		~TextureManager();

		// Reset all textures, useful after a screen resize
		void resetTextures();

		// Remove all textures in storage
		void removeAllTextures();

	protected:
		void addTexture(Texture* texture);

		void removeTexture(Texture* texture);

		// The stored textures
		std::vector<Texture*> textures;
	};
}