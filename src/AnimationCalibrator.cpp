#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Texture.h>
#include <Animation.h>
#include <GraphicsManager.h>


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
bool acceptableInput(char toTest, std::string inputs);
template <typename T> T getValidatedInput();
void saveFrames();
void loadFrames();
void changeFPS();

//SDL_Window* window;
TGA::GraphicsManager* graphicsMan;
TGA::Texture* texture;
TGA::Animation animation;
int SCREEN_WIDTH = 1024;
int SCREEN_HEIGHT = 512;
int fps = 0;

int main(int argc, char **argv)
{
	texture = new TGA::Texture();
   graphicsMan = new TGA::GraphicsManager();

	std::string fileName;

	char command;

	bool running;

	std::cout << "Animation Calibrator:\n" << "A program to run through animations and tweak frame delays and settings.\n\n"
		<< "Please have your animation in a single file with frames laid out however you want.\n"; 

	std::cout << "Please enter the file name of the image containing your animation: ";

	getline(std::cin, fileName);

   // Initialize the window to render into.
   graphicsMan->init(SCREEN_WIDTH, SCREEN_HEIGHT, "Animation Calibrator", 20, 30);

	// WHILE the texture hasn't loaded successfully
	while(!texture->loadTexture(fileName))
	{
		std::cout << "Enter the name of the image to try: ";

		getline(std::cin, fileName);
	}

	animation.setTexture(texture);

	running = true;

	displayMenu();

   std::cout << "At what rate should the animation run? (fps): ";
   fps = getValidatedInput<int>();

	while(running)
	{
		std::cout << "Command: ";
		command = getValidatedInput<char>();

		switch(command)
		{
			case 'A':
         case 'a':
				addFrame();
				break;

			case 'D':
         case 'd':
				deleteFrame();
				break;

			case 'X':
         case 'x':
				clearFrames();
				break;

			case 'C':
         case 'c':
				setDimensions();
				break;

			//case 'R':
   //      case 'r':
			//	setDelay();
			//	break;

			case 'T':
         case 't':
				resetTexture();
				break;

			case 'P':
         case 'p':
				playAnimation();
				break;

			case 'Y':
         case 'y':
				printFrames();
				break;

			case 'V':
         case 'v':
				viewFrame();
				break;

			case 'M':
         case 'm':
				displayMenu();
				break;

         case 'S':
         case 's':
            saveFrames();
            break;

         case 'L':
         case 'l':
            loadFrames();
            break;
            
         case 'F':
         case 'f':
            changeFPS();
            break;

			case 'Q':
         case 'q':
				running = false;
				break;

			default:
				break;
		}
	}

   std::cout << "Do you want to save your frames?(Y/N) ";
   std::cin >> command;

   if (std::string("Y y").find_first_of(command) != std::string::npos)
   {
      saveFrames();
   }
	
	texture->deleteMe();
	animation.deleteMe();

   delete graphicsMan;

   exit(0);
}

void displayMenu()
{
	std::cout  
		<< "Menu:\n" 
		<< "A - add frame(s)\n"
		<< "D - delete frame(s)\n"
		<< "X - clear all frames\n"
		<< "C - change a frame's dimensions\n"
		<< "F - change the FPS of all frames\n"
		<< "T - change the animation image\n"
		<< "P - play the entire animation\n"
		<< "Y - print all frames\n"
		<< "V - view a single frame\n"
		<< "M - display this menu\n"
      << "S - save the current frames\n"
      << "L - load frames from a file\n"
		<< "Q - quit the program\n";

	// std::cout << "SDL ERROR: " << SDL_GetError() << std::endl;
}

void addFrame()
{
	bool adding = true;
	//Uint32 delay;
	SDL_Rect frameRect;
	char keepGoing;

	while(adding)
	{
		std::cout << "Enter the left-most x point (0 if image is laid out vertically): ";
      frameRect.x = getValidatedInput<int>();

		std::cout << "Enter the top-most y point (0 if image is laid out horizontally): ";
      frameRect.y = getValidatedInput<int>();

		std::cout << "Enter the width: ";
      frameRect.w = getValidatedInput<int>();

		std::cout << "Enter the height: ";
		frameRect.h = getValidatedInput<int>();

      // Removed individual delays
		//std::cout << "Enter the delay (in milliseconds): ";
		//std::cin >> delay;

		animation.addFrame(frameRect, (Uint32)(1.0 / fps * 1000));//delay * 1000);

		std::cout << "Frame added.\n";

		std::cout << "Keep adding frames (Y/N): ";
		keepGoing = getValidatedInput<char>();

      while (!acceptableInput(keepGoing, "N n Y y"))
      {
         keepGoing = getValidatedInput<char>();
      }

		if (std::string("N n").find_first_of(keepGoing) != std::string::npos)
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
		frameNum = getValidatedInput<int>();

		animation.deleteFrame(frameNum);

		std::cout << "Removed frame " << frameNum << ".\n";

		std::cout << "Keep deleting frames (Y/N): ";
		keepGoing = getValidatedInput<char>();

      while (!acceptableInput(keepGoing, "N n Y y"))
      {
         keepGoing = getValidatedInput<char>();
      }

		if(std::string("N n").find_first_of(keepGoing) != std::string::npos)
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
	frame = getValidatedInput<GLuint>();

	animation.goToFrame(frame);

	animation.draw((GLfloat)SCREEN_WIDTH / 2 - texture->getWidth(), (GLfloat)SCREEN_HEIGHT / 2 - texture->getHeight());

   graphicsMan->swapBuffers();
}

void playAnimation()
{
	std::cout << "Enter the number of times to play the entire animation: ";

	int repetitions;
	repetitions = getValidatedInput<int>();
	animation.setRepetitions(repetitions);

	animation.reset();

	while(!animation.isDone())
	{
		animation.update();

		animation.draw((GLfloat)SCREEN_WIDTH / 2 - animation.getCurrentFrameDimensions().w / 2, (GLfloat)SCREEN_HEIGHT / 2 - animation.getCurrentFrameDimensions().h / 2);

		graphicsMan->swapBuffers();
	}

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
	frame = getValidatedInput<GLuint>();

	std::cout << "Enter the new left-most x position: ";
	newRect.x = getValidatedInput<int>();

	std::cout << "Enter the new top-most y position: ";
	newRect.y = getValidatedInput<int>();

	std::cout << "Enter the new width: ";
	newRect.w = getValidatedInput<int>();
	
	std::cout << "Enter the new height: ";
	newRect.h = getValidatedInput<int>();

	animation.setFrameBounds(frame, newRect);
	std::cout << "New dimensions set.\n";
}

void setDelay()
{
	Uint32 delay;

	std::cout << "Enter the frame number: ";
	
	GLuint frame;
	frame = getValidatedInput<GLuint>();

	std::cout << "Enter the new delay (in milliseconds): ";
	delay = getValidatedInput<Uint32>();

	animation.setDelay(frame, delay * 1000);
	std::cout << "Delay for frame " << frame << " set.\n";
}

void printFrames()
{
	std::cout << animation.printFrames();
}

bool acceptableInput(char toTest, std::string inputs)
{
   if (inputs.find_first_of(toTest) == std::string::npos)
   {
      std::cout << "'" << toTest << "'" << "is not a valid input.\n";
      std::cout << "Valid inputs are any of the following: " << inputs << "\n";
      std::cout << "Try again: ";

      return false;
   }

   return true;
}

template <typename T> T getValidatedInput()
{
   bool validated = false;
   T result;

   while (!validated)
   {
      std::cin >> result;

      // Check if the failbit has been set, meaning the beginning of the input
      // was not type T. Also make sure the result is the only thing in the input
      // stream, otherwise things like 2b would be a valid int.
      if (std::cin.fail() || std::cin.get() != '\n')
      {
         // Set the error state flag back to goodbit. If you need to get the input
         // again (e.g. this is in a while loop), this is essential. Otherwise, the
         // failbit will stay set.
         std::cin.clear();

         // Clear the input stream using an empty while loop.
         while (std::cin.get() != '\n')
            ;

         // Throw an exception. Allows the caller to handle it any way you see fit
         // (exit, ask for input again, etc.)
         validated = false;

         std::cout << "Invalid input, please try again: ";
      }
      else
      {
         validated = true;
      }
   }

   return result;
}

void saveFrames() 
{
   std::ofstream outStream;
   std::string fileName;
   
#if defined(WIN32) || defined(_WIN32)
   char ch;
   
   while ( std::cin.get ( ch ) && ch != '\n' )
      ;
#endif

   std::cout << "What do you want to name the file? ";
   getline(std::cin, fileName);

   outStream.open(fileName.c_str(), std::ios::out);

   while (!outStream.is_open())
   {
      std::cout << "What do you want to name the file? ";
      getline(std::cin, fileName);

      outStream.open(fileName.c_str(), std::ios::out);
   }

   outStream << animation.printFrames();

   outStream.close();
}

void loadFrames()
{
   std::ifstream inStream;
   std::string fileName;
   
#if defined(WIN32) || defined(_WIN32)
   char ch;

   while ( std::cin.get ( ch ) && ch != '\n' )
      ;
#endif

   std::cout << "What is the name of the file? ";
   getline(std::cin, fileName);

   inStream.open(fileName.c_str(), std::ios::in);

   while (!inStream.is_open())
   {
      std::cout << "Couldn't open that file, try again: ";
      getline(std::cin, fileName);

      inStream.open(fileName.c_str(), std::ios::in);
   }

   std::string line, xStr, yStr, wStr, hStr, delayStr;
   std::string::size_type yNdx, hNdx;
   SDL_Rect rect;
   /*
      Frame: ###
      X: ###  Y: ###
      Width: ###  Height: ###
      Delay: ###
   */

   while (getline(inStream, line))
   {
      // Get "Frame: ###" line
      if (line.find("Frame:") == std::string::npos)
      {
         std::cout << "Incorrect file format in " << fileName << ". Line: " << line;
         break;
      }

      // Get "X: ## Y: ##" line
      getline(inStream, line);
      yNdx = line.find("Y: ");
      if (line.find("X: ") == std::string::npos || yNdx == std::string::npos)
      {
         std::cout << "Incorrect file format in " << fileName << ". Line: " << line;
         break;
      }

      // 3 is where "X: " ends
      xStr = line.substr(3, yNdx - 4);
      rect.x = atoi(xStr.c_str());

      yStr = line.substr(yNdx + 3);
      rect.y = atoi(yStr.c_str());

      // Get "Width: ## Height: ##" line
      getline(inStream, line);
      hNdx = line.find("Height: ");
      if (line.find("Width: ") == std::string::npos || yNdx == std::string::npos)
      {
         std::cout << "Incorrect file format in " << fileName << ". Line: " << line;
         break;
      }

      // 6 is where "Width: " ends
      wStr = line.substr(7, hNdx - 7);
      rect.w = atoi(wStr.c_str());

      hStr = line.substr(hNdx + 8);
      rect.h = atoi(hStr.c_str());

      // Get "Delay: ###" line
      getline(inStream, line);
      if (line.find("Delay: ") == std::string::npos)
      {
         std::cout << "Incorrect file format in " << fileName << ". Line: " << line;
         break;
      }
      
      // Disregard delay, disregard newline
      getline(inStream, line);

      animation.addFrame(rect, (Uint32) (1.0 / fps * 1000));
   }

   inStream.close();
}

void changeFPS()
{
   std::cout << "Enter new frame rate: ";
   std::cin >> fps;

   for (unsigned int i = 0; i < animation.getFrameCount(); i++)
   {
      animation.setDelay(i, (Uint32)(1.0 / fps * 1000));
   }
}