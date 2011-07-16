#include "../include/Texture.h"

namespace TGA
{
	Texture::Texture()
	{
		// Initialize all members with default values
	}

	Texture::Texture(std::string fileName)
	{
		// CALL loadTexture(filename)
	}

	Texture::~Texture()
	{
		// CALL deleteMe()
	}

	void Texture::loadTexture(std::string fileName)
	{
		// Create an SDL_Surface with a call to IMG_Load and the fileName

		// IF the surface is NULL

			// Print an error message and stop

		// ENDIF

		// CALL SDL_DisplayFormatAlpha(image)

		// Set this texture's fileName to the fileName

		// Set the width and height to the appropriate surface values

		// Generate the texture (glGenTextures)

		// Bind the texture

		// Set up glTexParameter(s)

		// CALL glTexImage2D

		// Free the surface

		// Add this texture to the TextureManager
	}

	void Texture::deleteMe()
	{
		// Remove this texture from the TextureManager
	}

	void Texture::reset()
	{
		// CALL loadTexture(fileName)
	}

	void Texture::draw(GLfloat xPos, GLfloat yPos)
	{
		// Push the current matrix (glPushMatrix)

		// Bind the texture (glBindTexture)

		// Begin drawing

			// Assign the texture coords for each corner and the vertexes (4 blocks of 2 lines of glTexCoord, glVertex)

		// End drawing

		// Pop the current matrix (glPopMatrix)
	}

	void Texture::drawSection(GLfloat xPos, GLfloat yPos, SDL_Rect section)
	{
		// CALL drawSection(xPos, yPos, section->x, section->y, section->w, section->h)
	}

	void Texture::drawSection(GLfloat xPos, GLfloat yPos, int sectX, int sectY, int sectWidth, int sectHeight)
	{
		// Push the current matrix (glPushMatrix)

		// Bind the texture (glBindTexture)

		// Begin drawing

			// Assign the texture coords for each corner and the vertexes (4 blocks of 2 lines of glTexCoord, glVertex)

		// End drawing

		// Pop the current matrix (glPopMatrix)
	}

	GLfloat Texture::getWidth()
	{
		// Return the width
	}

	GLfloat Texture::getHeight()
	{
		// Return the height
	}
}