#pragma once

#include "../include/ProjIncludes.h"

namespace TGA
{
	// A texture with ID, filename, width, and height
	class Texture
	{
		friend class TextureManager;

	public:
		// Constructors/Destructor
		Texture();
		Texture(std::string fileName);
		~Texture();

		// Load texture from an image
		void loadTexture(std::string fileName);

		// Delete texture
		void deleteMe();

		// Reset the texture
		void reset();

		// Draw an entire texture
		void draw(GLfloat xPos, GLfloat yPos);

		// Draw a section of a texture
		void drawSection(GLfloat xPos, GLfloat yPos, SDL_Rect section);

		// Draw a section of a texture
		void drawSection(GLfloat xPos, GLfloat yPos, int sectX, int sectY,
			int sectWidth, int sectHeight);

		GLfloat getWidth();

		GLfloat getHeight();

	private:
		GLuint texture;
		std::string fileName;
		GLfloat width;
		GLfloat height;
	};
}