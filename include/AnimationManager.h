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
		GLuint createAnimation(std::vector<GLuint> frames, Uint32 delay);

		// Remove an animation
		void remove(GLuint animationID);
		
		// Remove all animations
		void removeAll();

		// Pause an animation
		void pause(GLuint animationID);
		
		// Pause all animations
		void pauseAll();
		
		// Update an animation
		void update(GLuint animationID);

		// Update all animations
		void updateAll();

		// Reset an animation
		void reset(GLuint animationID);

		// Reset all animations
		void resetAll();

		// Set the repetitions of an animation
		void setRepetitions(GLuint animationID, GLuint frame);

		// Go to a specific frame
		void goToFrame(GLuint animationID, GLuint frame);

		// Draw an animation at a given position
		void drawAnimation(GLuint animationID, GLfloat xPos, GLfloat yPos);

	private:
		// The animations and their IDs
		std::map<GLuint, Animation> animations;
	};
}