#include "../include/Animation.h"

namespace TGA
{
	Animation::Animation()
	{
		// Set texture to NULL

		// Initialize frames

		// Initialize other variables to default values

		// Add this animation to the Animation Manager
	}

	Animation::Animation(Texture* texture)
	{
		// Set texture to the texture

		// Initialize frames

		// Initialize other variables to default values

		// Add this animation to the Animation Manager
	}

	Animation::~Animation()	{}

	void Animation::update()
	{
		// IF the texture is NOT empty, AND the animation is NOT paused OR NOT done, AND repetitions is NOT 0, AND there are frames
			
			// IF enough time has passed based on the current frame and its delay

				// Increment the current frame

				// Update lastUpdate

				// IF the current frame is out of bounds

					// IF it is not running indefinitely

						// IF it is out of repetitions

							// Set it to paused

						// ELSE

							// Decrement repetitions

							// IF repetitions is 0

								// Set the animation to done

							// ENDIF

						// ENDIF
		
					// ENDIF
			
					// Set the current frame back to 0

				// ENDIF

			// ENDIF
		
		// ENDIF
	}

	void Animation::pause()
	{
		// Set the animation to paused
	}
	
	void Animation::resume()
	{
		// Set the animation to NOT paused
		// Update lastUpdate
	}

	void Animation::reset()
	{
		// Set the current frame back to 0
		// Set done to false
		// Update lastUpdate
	}

	bool Animation::isDone()
	{
		// Return done
	}

	void Animation::deleteMe()
	{
		// Remove this animation from the Animation Manager
	}

	void Animation::addFrame(SDL_Rect frameRect, Uint32 delay)
	{
		// Tack this frame and it's delay onto the end of frames
	}

	void Animation::goToFrame(GLuint frame)
	{
		// IF the frame desired exists
		
			// Set the current frame to this frame
			
			// Update lastUpdate
		
		// ENDIF
	}

	void Animation::setRepetitions(int repetitions)
	{
		// Set repetitions
	}

	void Animation::setTexture(Texture* texture)
	{
		// Set texture
	}

	void Animation::setDelay(GLuint frame, Uint32 delay)
	{
		// IF the frame exists
		
			// Get the desired frame and set it's delay to this one

		// ENDIF
	}
	
	void Animation::setFrameBounds(GLuint frame, SDL_Rect newBounds)
	{
		// IF the frame exists

			// Get the desired frame and update it's bounds

		// ENDIF
	}

	void Animation::draw(GLfloat xPos, GLfloat yPos)
	{
		// IF the texture exists

			// CALL the texture's drawSection method with xPos, yPos, and the current frame

		// ENDIF
	}

	GLuint Animation::getFrameCount()
	{
		// Return the number of items in frames
	}
}