#include "TextureManager.hpp"

TextureManager* TextureManager::s_pInstance = nullptr;

TextureManager::TextureManager()
{

}

bool TextureManager::I_init()
{
    int flags = IMG_INIT_PNG;
    if( !( IMG_Init( flags ) & flags ) )
    {
        cout <<  "Failed to initialize SDL_image" << endl;
        cout << "SDL error: " <<  IMG_GetError() << endl;
        return false; 
    }
    return true;
}

bool TextureManager::init()
{
    return Instance()->I_init();
}

TextureManager* TextureManager::Instance()
{
    if (!s_pInstance)
    {
        s_pInstance = new TextureManager();
    }
    return s_pInstance;
}

bool TextureManager::I_loadTexture(
    string id, string path, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(path.c_str());

    if (!tempSurface)
    {
        cout << "Failed to load image" << endl;
        cout << SDL_GetError() << endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface
                            (Game::getRenderer(), tempSurface);
    if(!texture)
    {
        cout << "Failed to create texture" << endl;
        cout << SDL_GetError() << endl;
        return false;
    }

    m_textureMap[id] = texture;

    SDL_FreeSurface(tempSurface);
    return true;
}

void TextureManager::I_removeTexture(string id)
{
    m_textureMap.erase(id);
}

void TextureManager::I_draw(string id, int x, int y, int width, int height,
    SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect destRect;
    destRect.w = width;
    destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    // Copy the texture to the renderer
    SDL_RenderCopyEx(Game::getRenderer(), m_textureMap[id], 
                     nullptr, &destRect, 0, 0, flip);
}

/*Loads textures for rendering

Args:
    id (string): an identifier for the texture
    path (string): the path of the image
    renderer (SDL_Renderer*): a renderer for the window

Returns:
    bool: True on success and false on failure
*/
bool TextureManager::loadTexture(string id, string path, SDL_Renderer* renderer)
{
    return Instance()->I_loadTexture(id, path, renderer);
}

/*Deload texture (remove from map)

Args:
    id (string): identifier for the texture
*/
void TextureManager::removeTexture(string id)
{
    Instance()->I_removeTexture(id);
}

/*Renders a texture to the renderer

Args:
    id (string): identifier for the texture
    x (int): the horizontal position of top left corner in pixels
    y (int): the vertical position of top left corner in pixels
    width (int): the width of the rendering in pixels
    height (int): the height of the rendering in pixels
    renderer (SDLRenderer*): renderer for the window
    flip (SDL_RendererFlip): flag for flipping texture
*/
void TextureManager::draw(string id, int x, int y, int width, int height,
    SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    Instance()->I_draw(id, x, y, width, height, renderer, flip);
}

void TextureManager::I_clean()
{
    for (auto element : m_textureMap)
    {
        SDL_DestroyTexture(element.second);
        element.second = nullptr;
    }
    m_textureMap.clear();

    IMG_Quit();
}

void TextureManager::clean()
{
    Instance()->I_clean();
    delete s_pInstance;
    s_pInstance = nullptr;
}