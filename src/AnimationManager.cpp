#include "../include/AnimationManager.h"

namespace TGA
{
	AnimationManager::AnimationManager()
	{

	}

	AnimationManager::~AnimationManager()
	{

	}

	GLuint AnimationManager::createAnimation( std::vector<GLuint> frames, std::vector<Uint32> delays )
	{
		return 0;
	}

	GLuint AnimationManager::createAnimation( std::vector<GLuint> frames, Uint32 delay )
	{
		return 0;
	}

	void AnimationManager::remove( GLuint animationID )
	{

	}

	void AnimationManager::removeAll()
	{

	}

	void AnimationManager::pause( GLuint animationID )
	{

	}

	void AnimationManager::pauseAll()
	{

	}

	void AnimationManager::update( GLuint animationID )
	{

	}

	void AnimationManager::updateAll()
	{

	}

	void AnimationManager::reset( GLuint animationID )
	{

	}

	void AnimationManager::resetAll()
	{

	}

	void AnimationManager::setRepetitions( GLuint animationID, GLuint frame )
	{

	}

	void AnimationManager::goToFrame( GLuint animationID, GLuint frame )
	{

	}

	void AnimationManager::drawAnimation( GLuint animationID, GLfloat xPos, GLfloat yPos )
	{

	}
}