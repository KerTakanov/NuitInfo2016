#ifndef _GRILLE_HPP_
#define _GRILLE_HPP_

#include <map>
#include <utility>

#include "puyo.hpp"
#include "point.hpp"

class Grille
{
public:
    Grille(int lignes, int colonnes);
private:
    std::map<std::pair<int, int>, PuyoPtr> _grille;
};

#endif