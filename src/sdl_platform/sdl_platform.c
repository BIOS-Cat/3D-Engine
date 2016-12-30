#include <SDL2/SDL.h>
#include <stdio.h>

#include <sdl_platform/sdl_platform.h>

int HandleEvent(SDL_Event *Event)
{
    int ShouldQuit = 0;
 
    switch(Event->type)
    {
        case SDL_QUIT:
        {
            printf("SDL_QUIT\n");
            ShouldQuit = 1;
        } break;

        case SDL_WINDOWEVENT:
        {
            switch(Event->window.event)
            {
                case SDL_WINDOWEVENT_RESIZED:
                {
                    printf("SDL_WINDOWEVENT_RESIZED (%d, %d)\n", Event->window.data1, Event->window.data2);
                } break;

                case SDL_WINDOWEVENT_FOCUS_GAINED:
                {
                    printf("SDL_WINDOWEVENT_FOCUS_GAINED\n");
                } break;

                case SDL_WINDOWEVENT_EXPOSED:
                {
                    SDL_Window *Window = SDL_GetWindowFromID(Event->window.windowID);
                    SDL_Renderer *Renderer = SDL_GetRenderer(Window);
                    static int IsWhite = 1;
                    if (IsWhite == 1)
                    {
                        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
                        IsWhite = 0;
                    }
                    else
                    {
                        SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
                        IsWhite = 1;
                    }
                    SDL_RenderClear(Renderer);
                    SDL_RenderPresent(Renderer);
                } break;
            }
        } break;
    }
    
    return(ShouldQuit);
}

int app_exec(int argc, char **argv){
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *Window = SDL_CreateWindow("BIOS Cat",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640,
                                          480,
                                          SDL_WINDOW_RESIZABLE);
    if(Window)
    {
        // Create a "Renderer" for our window.
        SDL_Renderer *Renderer = SDL_CreateRenderer(Window,
                                                    -1,
                                                    0);
        if (Renderer)
        {
            int running = 1;
            while(running)
            {
                SDL_Event Event;
                SDL_WaitEvent(&Event);
                if (HandleEvent(&Event))
                {
                    break;
                }
            }
        }
        else
        {
            // TODO: Log something
        }
    }
    else
    {
        // TODO: Log something
    }
    
    SDL_Quit();
    return(0);
}
