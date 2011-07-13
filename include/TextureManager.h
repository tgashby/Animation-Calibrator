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

		// Load textures from images
		GLuint loadTexture(std::string fileName);

		// Load a texture from memory
		GLuint loadTextureFromMem(SDL_Surface* surface, std::string filename = "");

		// Reset all textures, useful after a screen resize
		void resetTextures();

		// Create a texture section
		GLuint createTextureSection(GLuint textureID, Section section);

		// Remove a texture from the stored textures
		void removeTexture(GLuint textureID);

		// Remove a texture section from the stored textures
		void removeTextureSection(GLuint sectionID);

		// Draw a texture at the given location
		void drawTexture(GLuint textureID, GLfloat xPos, GLfloat yPos);

		// Draw a texture section at the given location
		void drawTextureSection(GLuint sectionID, GLfloat xPos, GLfloat yPos);

		// Get a texture's width
		GLfloat getTextureWidth(GLuint textureID);

		// Get a texture's height
		GLfloat getTextureHeight(GLuint textureID);

		// Remove all textures in storage
		void removeAllTextures();

		// Remove all texture sections in storage
		void removeAllTextureSections();

	protected:
		// The stored textures
		std::map<GLuint, Texture> textures;

		// The stored texture sections
		std::map<GLuint, Section> sections;
	};
}