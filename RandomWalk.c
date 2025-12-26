#include "RandomWalk.h"
#include "ColorFormat/ColorFormat.h"

void RandomMove(SDL_Rect *agent, int direction)
{
    switch(direction)
    {
        case 0: (agent->y)--; break;
        case 1: (agent->y)++; break;
        case 2: (agent->x)--; break;
        case 3: (agent->x)++; break;
    }
    if(direction > 3)
    {
        fprintf(stderr, "Impossible integer representation of direction generated.\n");
        exit(-1);
    }
}

Agent *InitializeAgents(int num_agents, SDL_Surface *psurface)
{
    SDL_Rect rect = {WIDTH / 2, HEIGHT / 2, 2, 2}; // 2x2 rect, centered in middle of surface
    Agent *agents = calloc(num_agents, sizeof(Agent));
    for(int i = 0; i < num_agents; i++)
    {
        agents[i].rect = rect;
        agents[i].color = GetRandomColor(psurface);
    }
    return agents;
}

Uint32 GetRandomColor(SDL_Surface *psurface) 
{
    float randfloat = (double)rand() / RAND_MAX; // random float [0,1]
    HSL hslColor = {randfloat, 1, 0.5};
    RGB rbgColor = hsl2rgb(hslColor.h, hslColor.s, hslColor.l);
    Uint32 color = SDL_MapRGB(psurface->format, rbgColor.r, rbgColor.g, rbgColor.b);
    return color;
}

