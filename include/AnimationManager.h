#pragma once

#include "../include/Animation.h"

namespace TGA
{
	class AnimationManager
	{
		AnimationManager();
		~AnimationManager();

		// Create an animation with frames and varying delays
		GLuint createAnimation(std::vector<GLuint> frames, std::vector<Uint32> delays);
		
		// Create an animation with frames and a universal delay
		GLuint createAnimation(std::vectore<GLuint> frames, Uint32 delay);

		void remove(GLuint animationID);
		void removeAll();

		void pause(GLuint animationID);
		void pauseAll();

		void update(GLuint animationID);
		void updateAll();

		void reset(GLuint animationID);
		void resetAll();

		void setRepetitions(GLuint animationID, GLuint frame);

		void goToFrame(GLuint animationID, GLuint frame);

		void drawAnimation(GLuint animationID, GLfloat xPos, GLfloat yPos);

	private:
		std::map<GLuint, Animation> animations;
	};
}