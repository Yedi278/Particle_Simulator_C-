#ifndef PHANDLER_H
#define PHANDLER_H

#include "Particle.h"
#include <vector>

/**
 * @brief The PHandler class
 * @details The PHandler class is responsible for handling the particles in the simulation. Physics wise.
 */
class PHandler
{
private:
    std::vector<Particle> _particles;
    typedef unsigned long int size_type;

    SDL_Renderer* _renderer;
    size_type _nParticles;
    
public:
    PHandler(size_type nParticles, SDL_Renderer* renderer, unsigned int width, unsigned int height);
    
    void Update();
    void Render();

    ~PHandler();
};

#endif // PHANDLER_H