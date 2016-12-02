#include "renderer.hpp"

Renderer::Renderer()
{
    _window = WindowPtr(new sf::RenderWindow(sf::VideoMode(20*32, 20*32), "SFML works!"));
    _window->setFramerateLimit(60);
}

WindowPtr Renderer::get_window()
{
    return _window;
}

void Renderer::display()
{
    _window->display();
}

bool Renderer::isOpen()
{
    return _window->isOpen();
}