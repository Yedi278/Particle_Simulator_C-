#include <iostream>
#include "Macros.h"
#include "Engine.h"

Engine::Engine() : _window(nullptr), _renderer(nullptr), _isRunning(false), _pHandler(nullptr), _width(800), _height(600){

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        LOG_ERROR("Error initializing SDL: " << SDL_GetError());
        return;
    }

    _window = SDL_CreateWindow("Particle SImulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);
    if(_window == nullptr){
        LOG_ERROR("Error creating window: " << SDL_GetError());
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if(_renderer == nullptr){
        LOG_ERROR("Error creating renderer: " << SDL_GetError());
        return;
    }

    try{
        _pHandler = new PHandler(100, _renderer, _width, _height);
    }catch(...){
        LOG_ERROR("Error creating particle handler");
        _pHandler = nullptr;
        throw;
    }

    _isRunning = true;
    LOG_GREEN("Engine initialized");
}

void Engine::Update(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            _isRunning = false;
            break;
        default:
            break;
    }
}

bool Engine::isRunning(){
    return _isRunning;
}

void Engine::Render() {
    SDL_SetRenderDrawColor(_renderer, BLACK, 255);
    SDL_RenderClear(_renderer);
    _pHandler->Update();
    _pHandler->Render();
    SDL_RenderPresent(_renderer);
}

Engine::~Engine(){
    delete _pHandler;
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    LOG_GREEN("Engine Closed");
}