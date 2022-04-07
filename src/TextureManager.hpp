#pragma once
#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.hpp"

using namespace std;

enum window_centre{
    HORIZONTAL_CENTRE = -1, VERTICAL_CENTRE = -2 
};

class TextureManager
{
private:
    map<string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
    TextureManager();
    bool I_init();

    static TextureManager* Instance();

    // Implementation of static functions
    bool I_loadImageTexture(
        string id, string fileName, SDL_Renderer* renderer);
    bool I_loadTextTexture(string id, string fontPath, SDL_Colour colour, 
        int size, string text, SDL_Renderer* renderer);
    void I_removeTexture(string id);

    void I_drawImage(string id, int x, int y, int width, int height,
        SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void I_drawText(
        string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void I_clean();

public:

    static bool init();
    static bool loadImageTexture(
        string id, string imagePath, SDL_Renderer* renderer);
    static bool loadTextTexture(string id, string fontPath, SDL_Colour colour, 
        int size, string text, SDL_Renderer* renderer);
    static void removeTexture(string id);
    static void drawImage(string id, int x, int y, int width, int height,
        SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    static void drawText(
        string id, int x, int y, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    static void clean();
};