#include "../include/TextureManager.h"
#include "../include/AnimationManager.h"
#include "../include/InputManager.h"
#include "../include/ProjIncludes.h"

void displayMenu();
void addFrame(TGA::Animation&);
void viewFrame(TGA::Animation&);
void playAnimation(TGA::Animation&);
void resetTexture(TGA::Animation&);
void setDimensions(TGA::Animation&);
void setDelay(TGA::Animation&);

int main(int argc, char **argv)
{
	// Create a Texture to store the texture

	// Create an Animation to store the animation

	// Create integers to store the screen width and height

	// Create an SDL_Rect to store a frame's boundaries

	// Create a Uint32 to store the delay (in ms)

	// Create a string to store the file name

	// Create a letter to store the desired command

	// Create a boolean to determine if the user is done

	// Print out instructions for use

	// Ask the user for the name of the image

	// Take the input and store the filename

	//////////////////////////////////////////////////////////////////////////
	// Initialize the SDL window (1024x512) and GL context and all that stuff
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// Initialize all the OGL stuff
	//////////////////////////////////////////////////////////////////////////

	// Initialize the Texture with loadTexture

	// WHILE the texture is null

		// Tell the user the image is bad

		// Prompt for a new image

		// Take the input and store the filename

		// Initialize the Texture with loadTexture

	// ENDWHILE

	// WHILE the user isn't done with the program

		// Display the menu (displayMenu())

		// Store the letter

		// SWITCH based on letter chosen

			// CASE Add frames ('A')

				// CALL addFrame(animation)

			// ENDCASE

			// CASE Change frame dimensions ('C')

				// CALL setDimensions(animation)

			// ENDCASE

			// CASE change delay ('D')

				// CALL setDelay(animation)

			// ENDCASE

			// CASE new texture ('T')

				// CALL resetTexture(animation)

			// ENDCASE

			// CASE play the animation ('P')

				// CALL playAnimation(animation)

			// ENDCASE

			// CASE view a frame ('V')

				// CALL viewFrame(animation)

			// ENDCASE

			// CASE stop the program ('Q')

				// Delete GL context
			
				// Destroy Window

				// Set running to false
		
			// ENDCASE

		// ENDSWITCH

	// ENDWHILE

		
	return 0;
}

void displayMenu()
{
	// Display the menu options...
}

void addFrame(TGA::Animation& animation)
{
	// WHILE the user still wants to enter frames

		// Prompt the user for the next frame dimensions, delay in ms (one per line)

		// Store the xPos

		// Store yPos

		// Store the width

		// Store the height

		// Store the delay

		// Add this frame to the Animation

	// ENDWHILE
}

void viewFrame(TGA::Animation& animation)
{
	// Prompt the user for the frame number

	// Set the current frame

	// Draw the Animation

	// Swap buffers
}

void playAnimation(TGA::Animation& animation)
{
	// Prompt the user for the number of times to play the animation

	// Set the animations repetitions

	// WHILE the animation is not done

		// Update it

		// Draw it

		// Swap buffers

	// ENDWHILE
}

void resetTexture(TGA::Animation& animation)
{
	// Prompt user for new filename

	// Store filename

	// Initialize the Texture with loadTexture

	// WHILE the texture is null

		// Tell the user the image is bad

		// Prompt for a new image

		// Take the input and store the filename

		// Initialize the Texture with loadTexture

	// ENDWHILE
}

void setDimensions(TGA::Animation& animation)
{
	// Prompt the user for the frame number and dimensions (one per line)

	// Store the frame number

	// Store the xPos

	// Store yPos

	// Store the width

	// Store the height

	// Set the new frame boundsS
}

void setDelay(TGA::Animation& animation)
{
	// Prompt user for frame number and delay

	// Store frame number

	// Store delay

	// Set new frame delay
}
