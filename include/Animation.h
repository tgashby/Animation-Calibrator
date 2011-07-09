#pragma once

#include "../include/SDLIncludes.h"

namespace TGA
{
	class Animation
	{
	public:
		Animation();
		~Animation();

		void update();
		void pause();
		void resume();
		void reset();
		void goToFrame(GLuint frame);

		void setRepetitions(int repetitions);
		void setTexture(GLuint textureID, GLuint position);
		void setDelay(Uint32 delay, GLuint position);
		void draw(GLfloat xPos, GLfloat yPos);

		GLuint getFrameCount();

	private:
		std::vector<GLuint> textures;
		std::vector<Uint32> delays;

		GLuint currFrame;

		Uint32 lastUpdate;

		bool paused;
		int repetitions;
	};
}