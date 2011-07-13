#pragma once

#include "../include/SDLIncludes.h"

namespace TGA
{
	// A texture section with coordinates
	struct Section
	{
		GLfloat xMin;
		GLfloat xMax;
		GLfloat yMin;
		GLfloat yMax;
	};

	// A texture with ID, filename, width, and height
	struct Texture
	{
		GLuint textureID;
		std::string fileName;
		GLfloat width;
		GLfloat height;
	};

	// A texture section with ID, section, width, and height
	struct TextureSection
	{
		GLint sectionID;
		Section section;
		GLfloat width;
		GLfloat height;
	};
}