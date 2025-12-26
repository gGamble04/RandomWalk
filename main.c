#include "RandomWalk.h"
#include "ColorFormat/ColorFormat.h"

int main(int argc, char *argv[]) 
{
    int num_agents;
    srand(time(NULL));
    // Check command line args
    if(argc == 1) 
    {
        num_agents = 5;
    }
    else if (argc == 2) 
    {
        num_agents = atoi(argv[1]);
    }
    else
    {
        fprintf(stderr, "Usage: %s <number of agents>\n", argv[0]); 
        exit(-1);
    }

    // SDL2 initialization
    SDL_Window *pwindow =  SDL_CreateWindow("Random Walk", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Surface *psurface =  SDL_GetWindowSurface(pwindow);

    // Initialize agents
    Agent *agents = InitializeAgents(num_agents, psurface);
    
    // Event Loop
    int app_running = true;
    while(app_running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) 
            {
                app_running = false;
            }
        }
        // For each agent, get a direction, then move the agent SCALE times in that direction
        for(int i = 0; i < num_agents; i++)
        {
            int direction = rand() % 4; // 0->up, 1->down, 2->left, 3->right
            for(int j = 0; j < SCALE; j++)
            {
                RandomMove(&agents[i].rect, direction);
                SDL_FillRect(psurface, &agents[i].rect, agents[i].color);
            }
        }
        SDL_UpdateWindowSurface(pwindow);
        SDL_Delay(20);
    }

    free(agents);
    return 0;
}