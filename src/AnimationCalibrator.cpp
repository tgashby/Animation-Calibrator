#include "../include/TextureManager.h"
#include "../include/AnimationManager.h"
#include "../include/InputManager.h"
#include "../include/ProjIncludes.h"

void displayMenu();
void addFrame(TGA::Animation&);
void deleteFrame(TGA::Animation&);
void clearFrames(TGA::Animation&);
void viewFrame(TGA::Animation&);
void playAnimation(TGA::Animation&);
void resetTexture(TGA::Animation&);
void setDimensions(TGA::Animation&);
void setDelay(TGA::Animation&);

SDL_Window* window;
TGA::Texture* texture;
int SCREEN_WIDTH = 1024;
int SCREEN_HEIGHT = 512;

int main(int argc, char **argv)
{
	// Create a Texture to store the texture
	texture = new TGA::Texture();

	// Create an Animation to store the animation
	TGA::Animation animation;

	// Create a string to store the file name
	std::string fileName;

	// Create a letter to store the desired command
	char command;

	// Create a boolean to determine if the user is done
	bool running;

	// Print out instructions for use
	std::cout << "Animation Calibrator:\n" << "A program to run through animations and tweak frame delays and settings.\n"
		<< "Please have your animation in a single file with frames laid out however you want.\n"; 

	// Ask the user for the name of the image
	std::cout << "Please enter the file name of the image containing your animation: ";

	// Take the input and store the filename
	getline(std::cin, fileName);

	//////////////////////////////////////////////////////////////////////////
	// Initialize the SDL window (1024x512) and GL context and all that stuff
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

	// WHILE the texture is null
	while(!texture->loadTexture(fileName))
	{
		// Prompt for a new image
		std::cout << "Enter the name of the image to try: ";

		// Take the input and store the filename
		getline(std::cin, fileName);
	}
	// ENDWHILE

	animation.setTexture(texture);

	running = true;

	// WHILE the user isn't done with the program
	while(running)
	{
		// Display the menu (displayMenu())
		displayMenu();

		// Store the letter
		std::cin >> command;

		// SWITCH based on letter chosen
		switch(command)
		{
			// CASE Add frames ('A')
			case 'A':
				// CALL addFrame(animation)
				addFrame(animation);
				break;
				// ENDCASE

			case 'D':
				deleteFrame(animation);
				break;

			case 'X':
				clearFrames(animation);

			// CASE Change frame dimensions ('C')
			case 'C':
				// CALL setDimensions(animation)
				setDimensions(animation);
				break;
			// ENDCASE

			// CASE change delay ('D')
			case 'R':
				// CALL setDelay(animation)
				setDelay(animation);
				break;
			// ENDCASE

			// CASE new texture ('T')
			case 'T':
				// CALL resetTexture(animation)
				resetTexture(animation);
				break;
			// ENDCASE

			// CASE play the animation ('P')
			case 'P':
				// CALL playAnimation(animation)
				playAnimation(animation);
				break;
			// ENDCASE

			// CASE view a frame ('V')
			case 'V':
				// CALL viewFrame(animation)
				viewFrame(animation);
				break;
			// ENDCASE

			// CASE stop the program ('Q')
			case 'Q':
				// Delete GL context
				SDL_GL_DeleteContext(glContext);

				// Destroy Window
				SDL_DestroyWindow(window);

				// Set running to false
				running = false;
				break;
			// ENDCASE

			default:
				break;
		}
		// ENDSWITCH
	}
	// ENDWHILE

	return 0;
}

void displayMenu()
{
	// Display the menu options...
	std::cout  
		<< "Menu:\n" 
		<< "A - add frame(s)\n"
		<< "D - delete frame(s)\n"
		<< "X - clear all frames\n"
		<< "C - change a frame's dimensions\n"
		<< "R - set the delay of a frame\n"
		<< "T - change the animation image\n"
		<< "P - play the entire animation\n"
		<< "V - view a single frame\n"
		<< "Q - quit the program\n";

	std::cout << "SDL ERROR: " << SDL_GetError() << std::endl;

	std::cout << "Command: ";
}

void addFrame(TGA::Animation& animation)
{
	bool adding = true;
	Uint32 delay;
	SDL_Rect frameRect;
	char keepGoing;

	// WHILE the user still wants to enter frames
	while(adding)
	{
		// Prompt the user for the next frame dimensions, delay in ms (one per line)
		std::cout << "Enter the top-left x point (0 if image is laid out vertically): ";
		std::cin >> frameRect.x;

		// Store yPos
		std::cout << "Enter the top-left y point (0 if image is laid out horizontally): ";
		std::cin >> frameRect.y;

		// Store the width
		std::cout << "Enter the width: ";
		std::cin >> frameRect.w;

		// Store the height
		std::cout << "Enter the height: ";
		std::cin >> frameRect.h;

		// Store the delay
		std::cout << "Enter the delay (in milliseconds): ";
		std::cin >> delay;

		// Add this frame to the Animation
		animation.addFrame(frameRect, delay * 1000);

		std::cout << "Frame added.\n";

		std::cout << "Keep adding frames (Y/N): ";
		std::cin >> keepGoing;

		if(keepGoing == 'N')
		{
			adding = false;
		}
	}
	// ENDWHILE
}

void deleteFrame(TGA::Animation& animation)
{
	bool deleting = true;
	GLuint frameNum;
	char keepGoing;

	// WHILE the user still wants to enter frames
	while(deleting)
	{
		// Prompt the user for the next frame dimensions, delay in ms (one per line)
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
	// ENDWHILE
}

void clearFrames(TGA::Animation& animation)
{
	animation.clearFrames();
	std::cout << "All frames removed.";
}


void viewFrame(TGA::Animation& animation)
{
	GLuint frame;

	// Prompt the user for the frame number
	std::cout << "Enter the frame number: ";

	// Set the current frame
	std::cin >> frame;
	animation.goToFrame(frame);

	// Draw the Animation
	animation.draw(SCREEN_WIDTH / 2 - texture->getWidth(), SCREEN_HEIGHT / 2 - texture->getHeight());

	// Swap buffers
	SDL_GL_SwapWindow(window);	
}

void playAnimation(TGA::Animation& animation)
{
	// Prompt the user for the number of times to play the animation
	std::cout << "Enter the number of times to play the entire animation: ";

	// Set the animations repetitions
	int repetitions;
	std::cin >> repetitions;
	animation.setRepetitions(repetitions);

	animation.reset();

	// WHILE the animation is not done
	while(!animation.isDone())
	{
		// Update it
		animation.update();

		// Draw it
		animation.draw(SCREEN_WIDTH / 2 - texture->getWidth(), SCREEN_HEIGHT / 2 - texture->getHeight());

		// Swap buffers
		SDL_GL_SwapWindow(window);
	}
	// ENDWHILE
}

void resetTexture(TGA::Animation& animation)
{
	// Prompt user for new filename
	std::cout << "Enter a new file name for the animation image: ";

	// Store filename
	std::string fileName;
	getline(std::cin, fileName);
		
	// WHILE the texture is null
	while(!(texture->loadTexture(fileName)))
	{
		// Prompt for a new image
		std::cout << "Enter the name of the image to try: ";

		// Take the input and store the filename
		getline(std::cin, fileName);
	}
	// ENDWHILE

	animation.setTexture(texture);
	animation.clearFrames();
}

void setDimensions(TGA::Animation& animation)
{
	SDL_Rect newRect;

	// Prompt the user for the frame number and dimensions (one per line)
	std::cout << "Enter the frame number followed by the new dimensions (x, y, width, height): ";

	// Store the frame number
	GLuint frame;
	std::cin >> frame;

	// Store the xPos
	std::cin >> newRect.x;

	// Store yPos
	std::cin >> newRect.y;

	// Store the width
	std::cin >> newRect.w;

	// Store the height
	std::cin >> newRect.h;

	// Set the new frame bounds
	animation.setFrameBounds(frame, newRect);
}

void setDelay(TGA::Animation& animation)
{
	Uint32 delay;

	// Prompt user for frame number and delay
	std::cout << "Enter the frame number new delay (in milliseconds): ";
	
	// Store frame number
	GLuint frame;
	std::cin >> frame;

	// Store delay
	std::cin >> delay;

	// Set new frame delay
	animation.setDelay(frame, delay * 1000);
}

