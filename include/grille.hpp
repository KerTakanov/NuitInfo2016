#ifndef _GRILLE_HPP_
#define _GRILLE_HPP_

#include <map>
#include <utility>

#include "puyo.hpp"
#include "point.hpp"
#include "renderer.hpp"

typedef std::map<Point, PuyoPtr> MapGrille;

class Grille
{
public:
    Grille(Renderer& renderer, int lignes, int colonnes);

    void draw();

private:
    MapGrille _grille;
    sf::Sprite _grid;
    WindowPtr _window;
};

#endif