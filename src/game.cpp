#include <headers/game.h>

Game::Game()
{
    _Window = nullptr;
    _Renderer = nullptr;
    _screenWidth = 1024;
    _screenHeight = 600;
    _isRunning = false;
    message = nullptr;
    font = nullptr;
    text = nullptr;
    textColor.r=200; textColor.g = 0; textColor.b = 150;
    windowTitle = "snekk v2";
}

Game::~Game()
{
    Shutdown();
}

void Game::Input()
{
    SDL_Event Event;
    SDL_PollEvent(&Event);

    switch (Event.type)
    {
    case SDL_QUIT:
        _isRunning = false;
    }
}

void Game::Update()
{
}

void Game::Render()
{
}

void Game::gameLoop()
{
    unsigned int lastTick = SDL_GetTicks();

    while (_isRunning)
    {
        Input();
        Update();
        Render();
    }
}

void Game::Shutdown()
{
    SDL_DestroyWindow(_Window);
    SDL_Quit();
}

void Game::Initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL2: %s\n", SDL_GetError());
    }

    _Window = SDL_CreateWindow(windowTitle, _x, _y, _screenWidth, _screenHeight, 0);
    _Renderer = SDL_CreateRenderer(_Window, -1, 0);

    if (TTF_Init() == -1){
        printf("Error initializing TTF: %s\n", SDL_GetError());
    }

    _isRunning = true;
}

void Game::Run()
{
    {
        Initialize();

        gameLoop();

        Shutdown();
    }
}