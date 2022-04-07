#include "TextureManager.hpp"

TextureManager* TextureManager::s_pInstance = nullptr;

TextureManager::TextureManager()
{

}

bool TextureManager::I_init()
{
    int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !( IMG_Init( flags ) & flags ) )
    {
        cout <<  "Failed to initialize SDL_image" << endl;
        cout << "SDL error: " <<  IMG_GetError() << endl;
        return false; 
    }

    if (TTF_Init())
    {
        cout << "Failed to initialize SDL_ttf" << endl;
        cout << "TTF Error: " << TTF_GetError() << endl;
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

bool TextureManager::I_loadImageTexture(
    string id, string imagePath, SDL_Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(imagePath.c_str());

    if (!surface)
    {
        cout << "Failed to load image" << endl;
        cout << SDL_GetError() << endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface
                            (Game::getRenderer(), surface);
    if(!texture)
    {
        cout << "Failed to create texture" << endl;
        cout << SDL_GetError() << endl;
        return false;
    }

    SDL_FreeSurface(surface);
    surface = nullptr;

    m_textureMap[id] = texture;
    return true;
}

bool TextureManager::I_loadTextTexture(string id, string fontPath, 
    SDL_Colour colour, int size, string text, SDL_Renderer* renderer)
{
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), size);
    if (!font)
    {
        cout << "Failed to open font" << endl;
        cout << "TTF Error:" << TTF_GetError() << endl;
        return false;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(
        font, text.c_str(), colour);
    if (!surface) 
    {
        cout << "Failed to create text surface" << endl;
        cout << "TTF Error: " << TTF_GetError() << endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(
        renderer, surface);
    if (!texture)
    {
        cout << "Failed to create text texture" << endl;
        cout << "TTF Error: " << TTF_GetError() << endl;
        return false;
    }

    SDL_FreeSurface(surface);
    surface = nullptr;

    m_textureMap[id] = texture;
    return true;
}

bool TextureManager::loadTextTexture(string id, string fontPath, 
    SDL_Colour colour, int size, string text, SDL_Renderer* renderer)
{
    return Instance()->I_loadTextTexture(
        id, fontPath, colour, size, text, renderer);
}

void TextureManager::I_removeTexture(string id)
{
    SDL_DestroyTexture(m_textureMap[id]);
    m_textureMap[id] = nullptr;
    m_textureMap.erase(id);
}

void TextureManager::I_drawImage(string id, int x, int y, int width, int height,
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

void TextureManager::I_drawText(string id, int x, int y, SDL_Renderer* renderer, 
    SDL_RendererFlip flip)
{
    int textureWidth, textureHeight;
    SDL_QueryTexture(m_textureMap[id], nullptr, nullptr, &textureWidth, &textureHeight);

    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(Game::getRenderer(), &windowWidth, &windowHeight);

    switch (x)
    {
    case HORIZONTAL_CENTRE:
        x = (windowWidth - textureWidth) / 2;
        break;
    default:
        break;
    };

    switch (y)
    {
    case VERTICAL_CENTRE:
        y = (windowHeight - textureHeight) / 2;
        break;
    default:
        break;
    };

    Instance()->I_drawImage(id, x, y, textureWidth, textureHeight, renderer, flip);

}

void TextureManager::drawText(string id, int x, int y, SDL_Renderer* renderer, 
    SDL_RendererFlip flip)
{
    Instance()->I_drawText(id, x, y, renderer, flip);
}

/*Loads textures for rendering

Args:
    id (string): an identifier for the texture
    imagePath (string): the imagePath of the image
    renderer (SDL_Renderer*): a renderer for the window

Returns:
    bool: True on success and false on failure
*/
bool TextureManager::loadImageTexture(string id, string imagePath, SDL_Renderer* renderer)
{
    return Instance()->I_loadImageTexture(id, imagePath, renderer);
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
void TextureManager::drawImage(string id, int x, int y, int width, int height,
    SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    Instance()->I_drawImage(id, x, y, width, height, renderer, flip);
}

void TextureManager::I_clean()
{
    for (auto element : m_textureMap)
    {
        SDL_DestroyTexture(element.second);
        element.second = nullptr;
    }
    m_textureMap.clear();

    TTF_Quit();
    IMG_Quit();
}

void TextureManager::clean()
{
    Instance()->I_clean();
    delete s_pInstance;
    s_pInstance = nullptr;
}