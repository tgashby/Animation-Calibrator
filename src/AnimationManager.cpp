#include "../include/AnimationManager.h"

namespace TGA
{
	AnimationManager::AnimationManager()
	{
		// Clear the animations
		animations.clear();
	}

	AnimationManager::~AnimationManager()
	{
		// CALL removeAll
		removeAll();
	}

	void AnimationManager::removeAll()
	{
		// FOR all elements in animations
		for(unsigned int ndx = 0; ndx < animations.size(); ndx++)
		{
			// IF the animation is not NULL
			if(animations.at(ndx) != NULL)
			{
				// Delete the animation
				delete animations.at(ndx);
			}
			// ENDIF
		}
		// ENDFOR

		// Clear the animations
		animations.clear();
	}

	void AnimationManager::pauseAll()
	{
		// FOR all elements in animations
		for(unsigned int ndx = 0; ndx < animations.size(); ndx++)
		{
			// CALL pause() on the current animation
			animations.at(ndx)->pause();
		}
		// ENDFOR
	}

	void AnimationManager::resumeAll()
	{
		// FOR all elements in animations
		for(unsigned int ndx = 0; ndx < animations.size(); ndx++)
		{
			// CALL resume() on the current animation
			animations.at(ndx)->resume();
		}
		// ENDFOR
	}
	
	void AnimationManager::updateAll()
	{
		// FOR all elements in animations

			// CALL update() on the current animation

		// ENDFOR
	}

	void AnimationManager::resetAll()
	{
		// FOR all elements in animations
		for(unsigned int ndx = 0; ndx < animations.size(); ndx++)
		{
			// CALL reset() on the current animation
			animations.at(ndx)->reset();
		}
		// ENDFOR
	}

	void AnimationManager::addAnimation(Animation* animation)
	{
		// Tack this animation onto animations
		animations.push_back(animation);
	}

	void AnimationManager::removeAnimation(Animation* animation)
	{
		// Create an iterator and set it to find() on the vector
		std::vector<Animation*>::iterator itr = find(animations.begin(), animations.end(), animation);

		// IF the animation was found
		if(itr != animations.end())
		{
			// IF the animation is the last element
			if(itr == animations.end() - 1)
			{
				// CALL erase on the last element
				animations.erase(animations.end() - 1);
			}
			else
			{
				// Replace the animation with the last animation in the vector
				*itr = animations.at(animations.size() - 1);

				// Erase the last animation
				animations.erase(animations.end() - 1);
			}
		}

		// Delete the animation
		delete animation;
	}
}