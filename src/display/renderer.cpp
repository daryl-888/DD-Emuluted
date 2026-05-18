#include <SDL2/SDL.h>
#include <cstdint>

class Platform
{
    public:
    Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight) 
    {
        SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow(title, 0, 0, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
        
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, textureWidth, textureHeight);
    }

    ~Platform()
    {
        SDL_DestroyTexture(texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void update(void const* buffer, int pitch)
    {
        SDL_UpdateTexture(texture, nullptr, buffer, pitch);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    bool processInput(uint8_t* input)
    {
        bool quit = false;

        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
           switch (event.type)
           {
            case SDL_QUIT:
            {
                quit = true;
            }
                break;
            
                case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    {
                        quit = true;
                    }
                        break;

                    case SDLK_x:
                    {
                        input[0] = 1;
                    }
                        break;

                    case SDLK_1:
                    {
                        input[1] = 1;
                    }
                        break;
                    
                    case SDLK_2:
                    {
                        input[2] = 1;
                    }
                        break;
                    
                    case SDLK_3:
					{
						input[3] = 1;
					} 
                        break;

					case SDLK_q:
					{
						input[4] = 1;
					} 
                        break;

					case SDLK_w:
					{
						input[5] = 1;
					} 
                        break;

					case SDLK_e:
					{
						input[6] = 1;
					} 
                        break;

					case SDLK_a:
					{
						input[7] = 1;
					} 
                        break;

					case SDLK_s:
					{
						input[8] = 1;
					} 
                        break;

					case SDLK_d:
					{
						input[9] = 1;
					}
                        break;

					case SDLK_z:
					{
						input[0xA] = 1;
					} 
                        break;

					case SDLK_c:
					{
						input[0xB] = 1;
				    } 
                        break;

					case SDLK_4:
					{
						input[0xC] = 1;
					}
                        break;

					case SDLK_r:
					{
						input[0xD] = 1;
					} 
                        break;

					case SDLK_f:
					{
						input[0xE] = 1;
					} 
                        break;

					case SDLK_v:
					{
						input[0xF] = 1;
					} 
                        break;
					}
				} 
                    break;

                case SDL_KEYUP:
                {
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_x:
                        {
                            input[0] = 0;
                        }
                            break;

                        case SDLK_1:
                        {
                            input[1] = 0;
                        }
                            break;
                    
                        case SDLK_2:
                        {
                            input[2] = 0;
                        }
                            break;
                    
                        case SDLK_3:
                        {
                            input[3] = 0;
                        }
                            break;
                        
                        case SDLK_q:
                        {
                            input[4] = 0;
                        }
                            break;

                        case SDLK_w:
                        {
                            input[5] = 0;
                        }
                            break;

                        case SDLK_e:
                        {
                            input[6] = 0;
                        }
                            break;

                        case SDLK_a:
                        {
                            input[7] = 0;
                        }
                            break;

                        case SDLK_s:
                        {
                            input[8] = 0;
                        }
                            break;
                        
                        case SDLK_d:
                        {
                            input[9] = 0;
                        }
                            break;

                        case SDLK_z:
                        {
                            input[0xA] = 0;
                        }
                            break;
                        
                        case SDLK_c:
                        {
                            input[0xB] = 0;
                        }
                            break;

                        case SDLK_4:
                        {
                            input[0xC] = 0;
                        }
                            break;

                        case SDLK_r:
                        {
                            input[0xD] = 0;
                        }
                            break;

                        case SDLK_f:
                        {
                            input[0xE] = 0;
                        }
                            break;

                        case SDLK_v:
                        {
                            input[0xF] = 0;
                        }
                            break;
                    }
                }
                    break;
            }
        } 
        return quit;
    }
    
    private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
};