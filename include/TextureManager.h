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
		// Add a texture to be managed
		void addTexture(Texture* texture);
		// Remove a texture from being managed
		void removeTexture(Texture* texture);

		// The stored textures
		std::vector<Texture*> textures;
	};
}