#include <SFML/System/Time.hpp>

#include "assetsmanager.hpp"
#include "drawable.hpp"
#include "grille.hpp"

int main()
{
    Renderer r;
    sf::Texture t;
    AssetsManager::addTexture("Red Puyo", "assets/red_puyo.png");
    AssetsManager::addTexture("grid", "assets/grid.png");
    Drawable d = Drawable(r, AssetsManager::get_texture("Red Puyo"));

    sf::Clock clock;
    sf::Time deltat;

    Grille g(r, 20, 20);

    while (r.isOpen())
    {
        sf::Event event;
        deltat = clock.restart();
        while (r.get_window()->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                r.get_window()->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                d.move(-32, 0);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                d.move(32, 0);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                d.move(0, 32);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                d.move(0, -32);
        }
        g.draw();
        d.draw();
        r.display();
        r.get_window()->clear(sf::Color(0, 0, 0));
    }
    return 0;
}