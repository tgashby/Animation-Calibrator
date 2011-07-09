#pragma once

#include "../include/Texture.h"

namespace TGA
{
	class TextureManager
	{
	public:
		// Constructors/Destructors
		TextureManager();
		~TextureManager();

		// Load textures from images
		GLuint loadTexture(std::string fileName);
		GLuint loadTextureFromMem(SDL_Surface* surface, std::string filename = "");

		void resetTextures();

		GLuint createTextureSection(GLuint textureID, Section section);

		void removeTexture(GLuint textureID);
		void removeTextureSection(GLuint sectionID);

		void drawTexture(GLuint textureID, GLfloat xPos, GLfloat yPos);
		void drawTextureSection(GLuint sectionID, GLfloat xPos, GLfloat yPos);

		GLfloat getTextureWidth(GLuint textureID);
		GLfloat getTextureHeight(GLuint textureID);

		void removeAllTextures();
		void removeAllTextureSections();

	protected:
		std::map<GLuint, Texture> textures;
		std::map<GLuint, Section> sections;
	};
}