#include "PHandler.h"
#include <cassert>
#include "Macros.h"
#include <SDL.h>

PHandler::PHandler(size_type nParticles, SDL_Renderer* renderer, unsigned int width, unsigned int height) : _renderer(renderer), _nParticles(nParticles)
{
    assert(nParticles > 0);
    assert(renderer != nullptr);

    for(size_type i = 0; i < nParticles; i++){
        float x = (float)(rand() % width);
        float y = (float)(rand() % height);

        float vx = (float)(rand() % 1);
        float vy = (float)(rand() % 1);

        float ax = (float)(rand() % 1);
        float ay = (float)(rand() % 1);
        _particles.push_back(Particle(x,y,vx,vy,ax,ay,1,2,SDL_Color({WHITE, 255}), _renderer));
    }
}

void PHandler::Update()
{
    for(auto& p : _particles){
        
        for(auto& q : _particles){
            if(&p == &q) continue;
            Vector2D<float> r = (q.Position() - p.Position())*10000.f;
            float r2 = r.norm();
            float r3 = r2 * r2 * r2;
            Vector2D<float> f = r * (1.0f / r3) * 0.0001;
            p.Acceleration() += f;

            p.Position() += p.Velocity();
            p.Velocity() += p.Acceleration();
        }

    }
}

void PHandler::Render()
{
    for(auto& p : _particles){
        p.Render();
    }
}

PHandler::~PHandler()
{
}