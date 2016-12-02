#include "grille.hpp"

#include "assetsmanager.hpp"

Grille::Grille(Renderer& renderer, int lignes, int colonnes)
{
    _window = renderer.get_window();
    sf::Texture grid_text = AssetsManager::get_texture("grid");
    sf::Texture* _grid_text_repeated = new sf::Texture(grid_text);
    _grid_text_repeated->setRepeated(true);
    _grid = sf::Sprite(*_grid_text_repeated);
    _grid.setTextureRect({
        0, 
        0, 
        lignes * (int)_grid_text_repeated->getSize().x, 
        colonnes * (int)_grid_text_repeated->getSize().y});
}

void Grille::draw()
{
    _window->draw(_grid);
}