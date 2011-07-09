#pragma once

#include "../include/SDLIncludes.h"

namespace TGA
{
	struct Section
	{
		GLfloat xMin;
		GLfloat xMax;
		GLfloat yMin;
		GLfloat yMax;
	};

	struct Texture
	{
		GLuint textureID;
		std::string fileName;
		GLfloat width;
		GLfloat height;
	};

	struct TextureSection
	{
		GLint sectionID;
		Section section;
		GLfloat width;
		GLfloat height;
	};
}