#include <cmath>

namespace RK4{

    void solve(float& x, float& y, float& vx, float& vy, float ax, float ay, float dt){
        float k1x = vx;
        float k1y = vy;
        float k1vx = ax;
        float k1vy = ay;

        float k2x = vx + 0.5f * dt * k1vx;
        float k2y = vy + 0.5f * dt * k1vy;
        float k2vx = ax;
        float k2vy = ay;

        float k3x = vx + 0.5f * dt * k2vx;
        float k3y = vy + 0.5f * dt * k2vy;
        float k3vx = ax;
        float k3vy = ay;

        float k4x = vx + dt * k3vx;
        float k4y = vy + dt * k3vy;
        float k4vx = ax;
        float k4vy = ay;

        x += (dt / 6.0f) * (k1x + 2.0f * k2x + 2.0f * k3x + k4x);
        y += (dt / 6.0f) * (k1y + 2.0f * k2y + 2.0f * k3y + k4y);
        vx += (dt / 6.0f) * (k1vx + 2.0f * k2vx + 2.0f * k3vx + k4vx);
        vy += (dt / 6.0f) * (k1vy + 2.0f * k2vy + 2.0f * k3vy + k4vy);
    }
}

namespace EULER{

    void solve(float& x, float& y, float& vx, float& vy, float ax, float ay, float dt){
        x += vx * dt;
        y += vy * dt;
        vx += ax * dt;
        vy += ay * dt;
    }
}

namespace VERLET{

    void solve(float& x, float& y, float& vx, float& vy, float ax, float ay, float dt){
        x += vx * dt + 0.5f * ax * dt * dt;
        y += vy * dt + 0.5f * ay * dt * dt;
        vx += ax * dt;
        vy += ay * dt;
    }
}