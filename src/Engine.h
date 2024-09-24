#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include "PHandler.h"

/**
 * @brief The Engine class
 * @details The Engine class is responsible for running the grafix side of the simulator.
 */
class Engine{

private:
    /// @brief SDL window object.
    SDL_Window* _window;
    /// @brief SDL renderer object.
    SDL_Renderer* _renderer;
    
    /// @brief Boolean to check if the engine is running.
    bool _isRunning;

    /// @brief Particle handler object.
    PHandler* _pHandler;

    unsigned int _width;
    unsigned int _height;

public:

    Engine();

    void Update();
    bool isRunning();
    void Render();

    ~Engine();
};

#endif // ENGINE_H