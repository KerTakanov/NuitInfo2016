#include "renderer.hpp"

Renderer::Renderer()
{
    _window = WindowPtr(new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!"));
}