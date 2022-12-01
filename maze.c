#include <SDL2/SDL.h>
#include "maze.h"

bool init();
bool loadMedia();
void close();


SDL_Window * gWindow = NULL;
SDL_Surface * gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;    // Image to load and show on screen

int main(int argc, char *args[])
{
	// Start up SDL and create window
	if (!init())
		{
			printf("Failed to initialize!\n");
		}
	else
		{
			// Load media
			if (!loadMedia())
				{
					printf("Failed to load media!\n");
				}
			else
				{
					// Apply the image
					SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
					// Update the surface
					SDL_UpdateWindowSurface(gWindow);

					// Hack to get window to stay up
					SDL_Event e;
					bool quit = false;
					
					while (quit == false)
						{
							while (SDL_PollEvent(&e))
								{
									if(e.type == SDL_QUIT)
										quit = true;
								}
						}
				}
		}

	//Free resources and close SDL
	close();

	return 0;
}


/**
 * init - Starts up SDL and creates window
 */
bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError);
			success = false;
		}
	else
		{
			gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED,
									   SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
			if (gWindow == NULL)
				{
					printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
					success = false;
				}
			else
				{
					gScreenSurface = SDL_GetWindowSurface(gWindow);
				}
		}
	return (success);
}



/**
 * loadMedia - loads the media
 */
bool loadMedia()
{
	bool success = true;

	gHelloWorld = SDL_LoadBMP("images/hello_world.bmp");
	if (gHelloWorld == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "images/hello_world.bmp",
				   SDL_GetError());
			success = false;
		}

	return success;
}


/**
 * close - frees media and shuts down SDL
 */
void close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}
