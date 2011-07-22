#include "../include/Animation.h"
#include "../include/AnimationManager.h"

namespace TGA
{
	Animation::Animation()
	{
		// Set texture to NULL
		texture = NULL;

		// Initialize other variables to default values
		currFrame = 0;
		lastUpdate = SDL_GetPerformanceCounter();
		paused = false;
		done = false;
		repetitions = 0;

		// Add this animation to the Animation Manager
		Singleton<AnimationManager>::GetSingletonPtr()->addAnimation(this);
	}

	Animation::Animation(Texture* texture)
	{
		// Set texture to the texture
		this->texture = texture;

		// Initialize other variables to default values
		currFrame = 0;
		lastUpdate = SDL_GetPerformanceCounter();
		paused = false;
		done = false;
		repetitions = 0;

		// Add this animation to the Animation Manager
		Singleton<AnimationManager>::GetSingletonPtr()->addAnimation(this);
	}

	Animation::~Animation()	{}

	void Animation::update()
	{
		// IF the texture is NOT empty, AND the animation is NOT paused OR NOT done, AND repetitions is NOT 0, AND there are frames
		if(texture != NULL && !paused && !done && frames.size() > 0)	
		{
			// IF enough time has passed based on the current frame and its delay
			if(frames.at(currFrame).second < (SDL_GetPerformanceCounter() - lastUpdate))
			{
				// Increment the current frame
				currFrame++;

				// Update lastUpdate
				lastUpdate = SDL_GetPerformanceCounter();

				// IF the current frame is out of bounds
				if(currFrame == frames.size())
				{
					// IF it is not running indefinitely
					if(repetitions != -1)
					{
						if(repetitions == 0)
						{
							done = true;
							paused = true;
						}
						else 
						{
							repetitions--;
						}
					}

					currFrame = 0;
				}
			}
		}
	}

	void Animation::pause()
	{
		// Set the animation to paused
		paused = true;
	}
	
	void Animation::resume()
	{
		// Set the animation to NOT paused
		paused = false;

		// Update lastUpdate
		lastUpdate = SDL_GetPerformanceCounter();
	}

	void Animation::reset()
	{
		// Set the current frame back to 0
		currFrame = 0;

		// Set done to false
		done = false;
		paused = false;

		// Update lastUpdate
		lastUpdate = SDL_GetPerformanceCounter();
	}

	bool Animation::isDone()
	{
		// Return done
		return done;
	}

	bool Animation::isPaused()
	{
		return paused;
	}

	void Animation::deleteMe()
	{
		// Remove this animation from the Animation Manager
		Singleton<AnimationManager>::GetSingletonPtr()->removeAnimation(this);
	}

	void Animation::addFrame(SDL_Rect frameRect, Uint32 delay)
	{
		// Tack this frame and it's delay onto the end of frames
		frames.push_back(std::make_pair(frameRect, delay));
	}

	void Animation::deleteFrame(GLuint frameNum)
	{
		frames.erase(frames.begin() + frameNum);
	}

	void Animation::clearFrames()
	{
		frames.clear();
	}

	void Animation::goToFrame(GLuint frame)
	{
		// IF the frame desired exists
		if(frame < frames.size())
		{
			// Set the current frame to this frame
			currFrame = frame;
			
			// Update lastUpdate
			lastUpdate = SDL_GetPerformanceCounter();
		}
		// ENDIF
	}

	void Animation::setRepetitions(int repetitions)
	{
		// Set repetitions
		this->repetitions = repetitions;
	}

	void Animation::setTexture(Texture* texture)
	{
		delete this->texture;

		// Set texture
		this->texture = texture;
	}

	void Animation::setDelay(GLuint frame, Uint32 delay)
	{
		// IF the frame exists
		if(frame < frames.size())
		{
			// Get the desired frame and set it's delay to this one
			frames.at(frame).second = delay;
		}
		// ENDIF
	}
	
	void Animation::setFrameBounds(GLuint frame, SDL_Rect newBounds)
	{
		// IF the frame exists
		if(frame < frames.size())
		{
			// Get the desired frame and update it's bounds
			frames.at(frame).first = newBounds;
		}
		// ENDIF
	}

	void Animation::draw(GLfloat xPos, GLfloat yPos)
	{
		// IF the texture exists
		if(texture != NULL)
		{
			SDL_Rect tempRect = frames.at(currFrame).first;
			// CALL the texture's drawSection method with xPos, yPos, and the current frame
			texture->drawSection(xPos, yPos, tempRect.x, tempRect.y, tempRect.w, tempRect.h);  
		}
		// ENDIF
	}

	GLuint Animation::getFrameCount()
	{
		// Return the number of items in frames
		return frames.size();
	}
}
