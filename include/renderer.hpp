#ifndef _RENDERER_HPP_
#define _RENDERER_HPP_

#include <boost/smart_ptr.hpp>
#include <SFML/Graphics.hpp>

typedef boost::shared_ptr<sf::RenderWindow> WindowPtr;

class Renderer
{
public:
    Renderer();
private:
    WindowPtr _window;
};

#endif