#pragma once

#include <iostream>
#include <string>
#include <sdl2/SDL.h>
#include <sdl2/SDL_image.h>
#include <sdl2/SDL_ttf.h>

class Game {
    private:
        SDL_Renderer *_Renderer;
        SDL_Window *_Window;
        char *windowTitle;
        bool _isRunning;
        float frameRate;
        int _screenWidth, _screenHeight;
        int _x, _y;

        TTF_Font *font;
        SDL_Surface *message;
        SDL_Texture *text;
        SDL_Rect *textRect;
        SDL_Color *textColor;

        void Input();
        void Update();
        void Render();
        void Initialize();
        void gameLoop();
        void Shutdown();
    public:
        void Run();

        Game();
        ~Game();
};