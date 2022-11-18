#ifndef _MAZE_H_
#define _MAZE_H_

#include <SDL2/SDL.h>

/**
 * SDL_Instance - struct that holds addresses of window and renderer
 *
 * window - instance of a window
 * renderer - instance of a renderer
 *
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


/* Function Prototypes */
int init_instance(SDL_Instance *instance);
void draw_stuff(SDL_Instance instance);

#endif /* _MAZE_H_ */
