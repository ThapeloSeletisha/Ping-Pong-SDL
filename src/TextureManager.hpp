#pragma once
#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"

using namespace std;

class TextureManager
{
private:
    map<string, SDL_Texture*> m_textureMap;
    static TextureManager* s_pInstance;
    TextureManager(){};

    static TextureManager* Instance();

    // Implementation of static functions
    bool I_loadTexture(string id, string fileName, SDL_Renderer* renderer);
    void I_removeTexture(string id);

    void I_draw(string id, int x, int y, int width, int height,
                SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

public:

    static bool loadTexture(string id, string fileName, SDL_Renderer* renderer);
    static void removeTexture(string id);
    static void draw(string id, int x, int y, int width, int height,
              SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
};