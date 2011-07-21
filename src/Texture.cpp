#include "../include/Texture.h"
#include "../include/TextureManager.h"

namespace TGA
{
	Texture::Texture()
	{
		// Initialize all members with default values
		texture = 0;
		fileName = "";
		width = 0;
		height = 0;
	}

	Texture::Texture(std::string imgFileName)
	{
		// CALL loadTexture(filename)
		loadTexture(imgFileName);
	}

	Texture::~Texture()
	{
		// CALL deleteMe()
		deleteMe();
	}

	void Texture::loadTexture(std::string imgFileName)
	{
		// Create an SDL_Surface with a call to IMG_Load and the fileName
		SDL_Surface* image = IMG_Load(imgFileName.c_str());

		// IF the surface is NULL
		if(image == NULL)
		{
			// Print an error message and stop
			std::cout << "Error:" << SDL_GetError() << std::endl;
			return;
		}

		// CALL SDL_DisplayFormatAlpha(image)
		SDL_DisplayFormatAlpha(image);

		// Set this texture's fileName to the fileName
		fileName = imgFileName;

		// Set the width and height to the appropriate surface values
		width = (GLfloat)image->w;
		height = (GLfloat)image->h;

		// Generate the texture (glGenTextures)
		glGenTextures(1, &texture);

		// Bind the texture
		glBindTexture(GL_TEXTURE_2D, texture);

		// Set up glTexParameter(s)
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// CALL glTexImage2D
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

		// Free the surface
		SDL_FreeSurface(image);

		// Add this texture to the TextureManager
		Singleton<TextureManager>::GetSingletonPtr()->addTexture(this);
	}

	void Texture::deleteMe()
	{
		// Remove this texture from the TextureManager
		Singleton<TextureManager>::GetSingletonPtr()->removeTexture(this);
	}

	void Texture::reset()
	{
		// CALL loadTexture(fileName)
		loadTexture(fileName);
	}

	void Texture::draw(GLfloat xPos, GLfloat yPos)
	{
		// Push the current matrix (glPushMatrix)
		glPushMatrix();

		glEnable(GL_TEXTURE_2D);

		// Bind the texture (glBindTexture)
		glBindTexture(GL_TEXTURE_2D, texture);

		// Begin drawing
		glBegin(GL_QUADS);

			// Assign the texture coords for each corner and the vertexes (4 blocks of 2 lines of glTexCoord, glVertex)
			glTexCoord2d(0, 0);
			glVertex2f(xPos, yPos);

			glTexCoord2d(1, 0);
			glVertex2f(xPos + width, yPos);

			glTexCoord2d(1, 1);
			glVertex2f(xPos + width, yPos + height);
			
			glTexCoord2d(0, 1);
			glVertex2f(xPos, yPos + height);
		// End drawing
		glEnd();

		// Pop the current matrix (glPopMatrix)
		glPopMatrix();
	}

	void Texture::drawSection(GLfloat xPos, GLfloat yPos, SDL_Rect section)
	{
		// CALL drawSection(xPos, yPos, section->x, section->y, section->w, section->h)
		drawSection(xPos, yPos, section.x, section.y, section.w, section.h);
	}

	void Texture::drawSection(GLfloat xPos, GLfloat yPos, int sectX, int sectY, int sectWidth, int sectHeight)
	{
		// Push the current matrix (glPushMatrix)
		glPushMatrix();

		glEnable(GL_TEXTURE_2D);

		// Bind the texture (glBindTexture)
		glBindTexture(GL_TEXTURE_2D, texture);

		// Begin drawing
		glBegin(GL_QUADS);

			// Assign the texture coords for each corner and the vertexes (4 blocks of 2 lines of glTexCoord, glVertex)
			glTexCoord2d(sectX / width, sectY / height);
			glVertex2f(xPos, yPos);

			glTexCoord2d(sectWidth / width, sectY / height);
			glVertex2f(xPos + width, yPos);

			glTexCoord2d(sectWidth / width, sectHeight / height);
			glVertex2f(xPos + width, yPos + height);

			glTexCoord2d(sectX / width, sectHeight / height);
			glVertex2f(xPos, yPos + height);
		// End drawing
		glEnd();

		// Pop the current matrix (glPopMatrix)
		glPopMatrix();
	}

	GLfloat Texture::getWidth()
	{
		// Return the width
		return width;
	}

	GLfloat Texture::getHeight()
	{
		// Return the height
		return height;
	}
}