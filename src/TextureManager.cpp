#include "../include/TextureManager.h"

namespace TGA
{


	TextureManager::TextureManager()
	{
		// Clear all textures
	}

	TextureManager::~TextureManager()
	{
		// CALL removeAllTextures()
	}

	void TextureManager::resetTextures()
	{
		// FOR each texture in textures

			// Call reset on the current texture

		// ENDFOR
	}

	void TextureManager::removeAllTextures()
	{
		// FOR each texture in textures

			// Call deleteMe on the current texture

		// ENDFOR
	}

	void TextureManager::addTexture(Texture* texture)
	{
		// Create an iterator and call find() on textures

		// This if takes care of texture that were just reloaded
		// IF the texture was not found

			// Tack on the texture

		// ENDIF
	}

	void TextureManager::removeTexture(Texture* texture)
	{
		// Create an iterator and set it to find() on the vector

		// IF the texture was found

			// IF the texture is the last element

				// CALL erase on the last element

			// ELSE

				// Replace the texture with the last texture in the vector

				// Erase the last texture

			// ENDIF

		// Delete the texture
	}
}