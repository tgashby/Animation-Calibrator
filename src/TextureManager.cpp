#include "../include/TextureManager.h"

namespace TGA
{
	TextureManager::TextureManager()
	{
		// Clear all textures
		textures.clear();
	}

	TextureManager::~TextureManager()
	{
		// CALL removeAllTextures()
		removeAllTextures();
	}

	void TextureManager::resetTextures()
	{
		// FOR each texture in textures
		for(unsigned int ndx = 0; ndx < textures.size(); ndx++)
		{
			// Call reset on the current texture
			textures.at(ndx)->reset();
		}
	}

	void TextureManager::removeAllTextures()
	{
		// FOR each texture in textures
		for(unsigned int ndx = 0; ndx < textures.size(); ndx++)
		{
			// Call deleteMe on the current texture
			textures.at(ndx)->deleteMe();
		}
	}

	void TextureManager::addTexture(Texture* texture)
	{
		// Create an iterator and call find() on textures
		std::vector<Texture*>::iterator itr = find(textures.begin(), textures.end(), texture);

		// This if takes care of texture that were just reloaded
		// IF the texture was not found
		if(itr == textures.end())
		{
			// Tack on the texture
			textures.push_back(texture);
		}
	}

	void TextureManager::removeTexture(Texture* texture)
	{
		// Create an iterator and set it to find() on the vector
		std::vector<Texture*>::iterator itr = find(textures.begin(), textures.end(), texture);

		// IF the texture was found
		if(itr != textures.end())
		{
			// IF the texture is the last element
			if(itr == textures.end() - 1)
			{
				// CALL erase on the last element
				textures.erase(textures.end() - 1);
			}
			else
			{
				// Replace the texture with the last texture in the vector
				*itr = textures.at(textures.size() - 1);
				
				textures.erase(textures.end() - 1);
			}
		}

		delete texture;
	}
}