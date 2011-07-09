#include "../include/TextureManager.h"

namespace TGA
{


	TextureManager::TextureManager()
	{

	}

	TextureManager::~TextureManager()
	{

	}

	GLuint TextureManager::loadTexture( std::string fileName )
	{

	}

	GLuint TextureManager::loadTextureFromMem( SDL_Surface* surface, std::string filename)
	{

	}

	void TextureManager::resetTextures()
	{

	}

	GLuint TextureManager::createTextureSection( GLuint textureID, Section section )
	{

	}

	void TextureManager::removeTexture( GLuint textureID )
	{

	}

	void TextureManager::removeTextureSection( GLuint sectionID )
	{

	}

	void TextureManager::drawTexture( GLuint textureID, GLfloat xPos, GLfloat yPos )
	{

	}

	void TextureManager::drawTextureSection( GLuint sectionID, GLfloat xPos, GLfloat yPos )
	{

	}

	GLfloat TextureManager::getTextureWidth( GLuint textureID )
	{

	}

	GLfloat TextureManager::getTextureHeight( GLuint textureID )
	{

	}

	void TextureManager::removeAllTextures()
	{

	}

	void TextureManager::removeAllTextureSections()
	{

	}

}