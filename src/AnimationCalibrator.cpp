#include "../include/TextureManager.h"
#include "../include/AnimationManager.h"
#include "../include/InputManager.h"
#include "../include/ProjIncludes.h"

void displayMenu();
void addFrame();
void deleteFrame();
void clearFrames();
void viewFrame();
void playAnimation();
void resetTexture();
void setDimensions();
void setDelay();
void printFrames();

// Thread function
int handleAnimation(void*);

SDL_Window* window;
TGA::Texture* texture;
TGA::Animation animation;
int SCREEN_WIDTH = 1024;
int SCREEN_HEIGHT = 512;

// Bring "running" out to here

int main(int argc, char **argv)
{
	texture = new TGA::Texture();

	std::string fileName;

	char command;

	bool running;

	// Create a SDL_Thread*

	std::cout << "Animation Calibrator:\n" << "A program to run through animations and tweak frame delays and settings.\n\n"
		<< "Please have your animation in a single file with frames laid out however you want.\n"; 

	std::cout << "Please enter the file name of the image containing your animation: ";

	getline(std::cin, fileName);

	//////////////////////////////////////////////////////////////////////////
	// Initialize the SDL window and GL context and all that stuff
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow("Animation-Calibrator", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Initialize all the OGL stuff
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 0.0, 1000.0);

	glDisable(GL_DEPTH_TEST);

	glClearColor(1, 1, 1, 1);

	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLoadIdentity();
	//////////////////////////////////////////////////////////////////////////

	// WHILE the texture hasn't loaded successfully
	while(!texture->loadTexture(fileName))
	{
		std::cout << "Enter the name of the image to try: ";

		getline(std::cin, fileName);
	}

	animation.setTexture(texture);

	running = true;

	// Start the handleAnimation thread! (YAY!)

	displayMenu();

	while(running)
	{
		std::cout << "Command: ";
		std::cin >> command;

		switch(command)
		{
			case 'A':
				addFrame();
				break;

			case 'D':
				deleteFrame();
				break;

			case 'X':
				clearFrames();
				break;

			case 'C':
				setDimensions();
				break;

			case 'R':
				setDelay();
				break;

			case 'T':
				resetTexture();
				break;

			case 'P':
				playAnimation();
				break;

			case 'Y':
				printFrames();
				break;

			case 'V':
				viewFrame();
				break;

			case 'M':
				displayMenu();
				break;

			case 'Q':
				SDL_GL_DeleteContext(glContext);

				SDL_DestroyWindow(window);

				running = false;
				break;

			default:
				break;
		}
	}

	// Wait for the thread to finish
	
	texture->deleteMe();
	animation.deleteMe();

	return 0;
}

void displayMenu()
{
	std::cout  
		<< "Menu:\n" 
		<< "A - add frame(s)\n"
		<< "D - delete frame(s)\n"
		<< "X - clear all frames\n"
		<< "C - change a frame's dimensions\n"
		<< "R - set the delay of a frame\n"
		<< "T - change the animation image\n"
		<< "P - play the entire animation\n"
		<< "Y - print all frames\n"
		<< "V - view a single frame\n"
		<< "M - display this menu\n"
		<< "Q - quit the program\n";

	std::cout << "SDL ERROR: " << SDL_GetError() << std::endl;
}

void addFrame()
{
	bool adding = true;
	Uint32 delay;
	SDL_Rect frameRect;
	char keepGoing;

	while(adding)
	{
		std::cout << "Enter the left-most x point (0 if image is laid out vertically): ";
		std::cin >> frameRect.x;

		std::cout << "Enter the top-most y point (0 if image is laid out horizontally): ";
		std::cin >> frameRect.y;

		std::cout << "Enter the width: ";
		std::cin >> frameRect.w;

		std::cout << "Enter the height: ";
		std::cin >> frameRect.h;

		std::cout << "Enter the delay (in milliseconds): ";
		std::cin >> delay;

		animation.addFrame(frameRect, delay * 1000);

		std::cout << "Frame added.\n";

		std::cout << "Keep adding frames (Y/N): ";
		std::cin >> keepGoing;

		if(keepGoing == 'N')
		{
			adding = false;
		}
	}
}

void deleteFrame()
{
	bool deleting = true;
	GLuint frameNum;
	char keepGoing;

	while(deleting)
	{
		std::cout << "Enter frame number to delete: ";
		std::cin >> frameNum;

		animation.deleteFrame(frameNum);

		std::cout << "Removed frame " << frameNum << ".\n";

		std::cout << "Keep deleting frames (Y/N): ";
		std::cin >> keepGoing;

		if(keepGoing == 'N')
		{
			deleting = false;
		}
	}
}

void clearFrames()
{
	animation.clearFrames();
	std::cout << "All frames removed.\n";
}

void viewFrame()
{
	GLuint frame;

	std::cout << "Enter the frame number: ";

	std::cin >> frame;

	// Reset the animation

	animation.goToFrame(frame);

	// DELETE ME!
	animation.draw((GLfloat)SCREEN_WIDTH / 2 - texture->getWidth(), (GLfloat)SCREEN_HEIGHT / 2 - texture->getHeight());

	SDL_GL_SwapWindow(window);	
	// TO HERE!

	// Set repetitions to 0
}

void playAnimation()
{
	std::cout << "Enter the number of times to play the entire animation: ";

	int repetitions;
	std::cin >> repetitions;
	animation.setRepetitions(repetitions);

	animation.reset();

	// DELETE ME
	while(!animation.isDone())
	{
		animation.update();

		animation.draw((GLfloat)SCREEN_WIDTH / 2 - texture->getWidth(), (GLfloat)SCREEN_HEIGHT / 2 - texture->getHeight());

		SDL_GL_SwapWindow(window);
	}
	// TO HERE!

	// Change to "like"
	std::cout << "Hope you liked it!\n";
}

void resetTexture()
{
	std::cout << "Enter a new file name for the animation image: ";

	std::string fileName;
	getline(std::cin, fileName);
		
	// WHILE the texture hasn't loaded correctly
	while(!(texture->loadTexture(fileName)))
	{
		std::cout << "Enter the name of the image to try: ";

		getline(std::cin, fileName);
	}

	animation.setTexture(texture);
	animation.clearFrames();

	std::cout << "Texture reset and all frames removed.\n";
}

void setDimensions()
{
	SDL_Rect newRect;

	std::cout << "Enter the frame number: ";

	GLuint frame;
	std::cin >> frame;

	std::cout << "Enter the new left-most x position: ";
	std::cin >> newRect.x;

	std::cout << "Enter the new top-most y position: ";
	std::cin >> newRect.y;

	std::cout << "Enter the new width: ";
	std::cin >> newRect.w;
	
	std::cout << "Enter the new height: ";
	std::cin >> newRect.h;

	animation.setFrameBounds(frame, newRect);
	std::cout << "New dimensions set.\n";
}

void setDelay()
{
	Uint32 delay;

	std::cout << "Enter the frame number: ";
	
	GLuint frame;
	std::cin >> frame;

	std::cout << "Enter the new delay (in milliseconds): ";
	std::cin >> delay;

	animation.setDelay(frame, delay * 1000);
	std::cout << "Delay for frame " << frame << " set.\n";
}

void printFrames()
{
	std::cout << animation.printFrames();
}

int handleAnimation(void* unused)
{
	// WHILE the program is still running

		// Update the animation

		// Draw the animation

		// SDL_GL_SwapWindow(window)

	// ENDWHILE

	// RETURN
}
