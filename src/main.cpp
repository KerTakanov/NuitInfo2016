#include <SFML/System/Time.hpp>

#include "drawable.hpp"
#include "grille.hpp"

int main()
{
    Renderer r;
    sf::Texture t;
    t.loadFromFile("assets/red_puyo.png");
    Drawable d = Drawable(r, t);

    sf::Clock clock;
    sf::Time deltat;

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
            {
                // la touche "flèche gauche" est enfoncée : on bouge le personnage
                d.move(deltat.asSeconds(), -100, 0);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                d.move(deltat.asSeconds(), 100, 0);
            }
        }
        d.draw();
        r.display();
        r.get_window()->clear(sf::Color(0, 0, 0));
    }
    return 0;
}