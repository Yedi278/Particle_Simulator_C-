#include <iostream>
#include "Engine.h"

#undef main

int main(){

    Engine* engine = new Engine();
    
    while(engine->isRunning()){
        engine->Render();
        engine->Update();
    }

    delete engine;
    return 0;
}