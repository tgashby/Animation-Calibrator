#include "../include/AnimationManager.h"

namespace TGA
{
	AnimationManager::AnimationManager()
	{
		// Clear the animations
	}

	AnimationManager::~AnimationManager()
	{
		// CALL removeAll
	}

	void AnimationManager::removeAll()
	{
		// FOR all elements in animations

			// IF the animation is not NULL

				// Delete the animation

			// ENDIF

		// ENDFOR

		// Clear the animations
	}

	void AnimationManager::pauseAll()
	{
		// FOR all elements in animations

			// CALL pause() on the current animation

		// ENDFOR
	}

	void AnimationManager::resumeAll()
	{
		// FOR all elements in animations

			// CALL resume() on the current animation

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

			// CALL reset() on the current animation

		// ENDFOR
	}

	void AnimationManager::addAnimation(Animation* animation)
	{
		// Tack this animation onto animations
	}

	void AnimationManager::removeAnimation(Animation* animation)
	{
		// Create an iterator and set it to find() on the vector

		// IF the animation was found

			// IF the animation is the last element

				// CALL erase on the last element
			
			// ELSE

				// Replace the animation with the last animation in the vector

				// Erase the last animation

			// ENDIF

		// Delete the animation
	}
}