#ifndef DRAWER_TEXT_H
#define DRAWER_TEXT_H


#include <SDL2/SDL.h>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_ttf.h>


class DrawerText{
private:
    SDL2pp::SDLTTF ttf;
    SDL2pp::Font font;

public:
    DrawerText();

    void draw(SDL2pp::Renderer& renderer, const std::string& text);


    ~DrawerText();
};



#endif // DRAWER_TEXT_H
