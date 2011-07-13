#pragma once

#include "../include/SDLIncludes.h"

namespace TGA
{
	class Animation
	{
	public:
		Animation();
		~Animation();

		// Update the animation
		void update();

		// Pause the animation
		void pause();

		// Resume a paused animation
		void resume();

		// Move the animation back to its first frame
		void reset();

		// Go to a specified frame
		void goToFrame(GLuint frame);

		// Set how often this animation repeats (-1 for indefinitely)
		void setRepetitions(int repetitions);

		// Set the texture of a particular frame
		void setTexture(GLuint textureID, GLuint frame);

		// Set the delay of the specified frame
		void setDelay(Uint32 delay, GLuint frame);

		// Draw the animation at a location
		void draw(GLfloat xPos, GLfloat yPos);

		GLuint getFrameCount();

	private:
		// All textures that make up this animation
		std::vector<GLuint> textures;

		// All delays between textures
		std::vector<Uint32> delays;

		GLuint currFrame;

		// The last time this animation was updated
		Uint32 lastUpdate;

		bool paused;
		int repetitions;
	};
}