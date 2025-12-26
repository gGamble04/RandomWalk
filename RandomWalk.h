/**
 * @file RandomWalk.h
 * @brief Definitions for Random Walk simulation using SDL2.
 * @author Gabe Gamble
 * @date December 25, 2025
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<SDL2/SDL.h>

// Window dimensions and scale factor
#define WIDTH 900
#define HEIGHT 600
#define SCALE 10

/**
 * Agent structure representing a moving entity.
 */
typedef struct
{
    SDL_Rect rect; /**< Rectangle representing the agent's position and size */
    Uint32 color; /**< Unsigned 32-bit integer color representing the agent */
} Agent;

/**
 * @brief Moves the agent in a random direction.
 * @param agent Pointer to the SDL_Rect representing the agent's position
 * @param direction Integer representing the direction (0: up, 1: down, 2: left, 3: right)
 */
void RandomMove(SDL_Rect *agent, int direction);

/**
 * @brief Initializes an array of agents at the center of the surface with random colors.
 * @param num_agents Number of agents to initialize
 * @param psurface Pointer to the SDL_Surface where agents will be drawn
 * @return Pointer to the array of initialized agents
 */
Agent *InitializeAgents(int num_agents, SDL_Surface *psurface);

/**
 * @brief Generates a random color in Uint32 format suitable for SDL surfaces.
 * @param psurface Pointer to the SDL_Surface for color mapping
 * @return Uint32 color value
 */
Uint32 GetRandomColor(SDL_Surface *psurface);

