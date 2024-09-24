#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL.h>
#include "Vector2D.hpp"

class Particle{

private:
    Vector2D<float> pos;
    Vector2D<float> vel;
    Vector2D<float> acc;

    float _mass;
    float _radius;
    
    SDL_Color _color;

    SDL_Renderer* _renderer;
    
public:
    Particle(float x, float y, float vx, float vy, float ax, float ay, float mass, float radius, SDL_Color color, SDL_Renderer* renderer);
    
    Vector2D<float> Position() const;
    Vector2D<float> Velocity() const;
    Vector2D<float> Acceleration() const;

    Vector2D<float>& Position();
    Vector2D<float>& Velocity();
    Vector2D<float>& Acceleration();

    void Render();
    void Update();

    ~Particle();
};

#endif // PARTICLE_H