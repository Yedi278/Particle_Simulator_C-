#include "Particle.h"
#include <cassert>
#include "Gfx.hpp"

Particle::Particle(float x, float y, float vx, float vy, float ax, float ay, float mass, float radius, SDL_Color color, SDL_Renderer* renderer) 
            : _mass(mass), _color(color), _radius(radius), _renderer(nullptr), pos(0, 0), vel(0, 0), acc(0, 0)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(vx >= 0);
    assert(vy >= 0);
    assert(ax >= 0);
    assert(ay >= 0);
    assert(mass > 0);
    assert(radius > 0);
    assert(renderer != nullptr);

    _renderer = renderer;

    pos = Vector2D<float>(x, y);
    vel = Vector2D<float>(vx, vy);
    acc = Vector2D<float>(ax, ay);
}

void Particle::Update()
{
    
}

Vector2D<float> Particle::Position() const
{
    return pos;
}

Vector2D<float> Particle::Velocity() const
{
    return vel;
}

Vector2D<float> Particle::Acceleration() const
{
    return acc;
}

Vector2D<float>& Particle::Position()
{
    return pos;
}

Vector2D<float>& Particle::Velocity()
{
    return vel;
}

Vector2D<float>& Particle::Acceleration()
{
    return acc;
}

void Particle::Render()
{
    SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);
    
    SDL_RenderFillCircle(_renderer, pos.x(), pos.y(), _radius);

}

Particle::~Particle()
{

}