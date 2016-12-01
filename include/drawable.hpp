#ifndef _DRAWABLE_HPP_
#define _DRAWABLE_HPP_

#include <SFML/Graphics.hpp>

#include "renderer.hpp"

#include <iostream>

class Drawable
{
public:
    Drawable() {}
    Drawable(Renderer& renderer) : _window(renderer.get_window()) {}
    Drawable(Renderer& renderer, sf::Texture& _text) : _window(renderer.get_window()), _sprite(_text) {}
    void draw()
    {
        _window->draw(_sprite);
    }

    void move(float x, float y)
    {
        move(1, x, y);
    }

    void move(float delta, float x, float y)
    {
        _sprite.move(sf::Vector2f(x*delta, y*delta));
    }

private:
    WindowPtr _window;
    sf::Sprite _sprite;
};

#endif