#ifndef _ASSETSMANAGER_H_
#define _ASSETSMANAGER_H_

#include <boost/algorithm/string.hpp>
#include <boost/shared_ptr.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>
#include <map>
#include <exception>
#include <fstream>

typedef boost::shared_ptr<sf::Texture> TexturePtr;

class NoSuchTextureException : public std::exception
{
public:
    NoSuchTextureException(const std::string& texture_name) throw()
        : _texture_name(texture_name) {}

    virtual const char* what() const throw()
    {
        std::string err_msg = "Erreur ! Il n'existe pas de texture nommée "
            + _texture_name + " dans l'AssetsManager !";
        return err_msg.c_str();
    }

    virtual ~NoSuchTextureException() throw() {}
private:
    const std::string _texture_name;
};

class NoSuchTexturePathException : public std::exception {
public:
    NoSuchTexturePathException(std::string texture_path) throw()
        : _texture_path(texture_path) {}

    virtual const char* what() const throw()
    {
        std::string err_msg = "Erreur ! Le chemin \"" + _texture_path + "\" n'existe pas !";
        return err_msg.c_str();
    }

    virtual ~NoSuchTexturePathException() throw() {}
private:
    std::string _texture_path;
};


class AssetsManager
{
public:
    static AssetsManager& Instance() { return _instance; }
    static sf::Sprite get_sprite(std::string sprite_name)
    {
        if (_instance._textures.find(sprite_name) 
            != _instance._textures.end())
            return sf::Sprite(*(_instance._textures.at(sprite_name)));
        else throw(NoSuchTextureException(sprite_name));
    }

    static void addTexture(const std::string& texture_name, boost::shared_ptr<sf::Texture> texture)
    {
        _instance._textures[texture_name] = texture;
    }

    static void addTexture(std::string texture_name, std::string texture_path)
    {
        boost::shared_ptr<sf::Texture> texture(new sf::Texture());

        if (texture->loadFromFile(texture_path)) {
            addTexture(texture_name, texture);
        }
        else {
            throw NoSuchTexturePathException(texture_path);
        }
    }

    static void addTextureAtlas(const std::string& atlas_path)
    {
        std::ifstream f(atlas_path);
        std::string line;
        std::string texture_name;
        std::string texture_path;
        size_t index;

        if (f) {
            while (std::getline(f, line)) {
                index = line.find(':');

                //No string matching
                if (index == std::string::npos) continue;

                texture_name = line.substr(0, index);
                texture_path = line.substr(index + 1);

                boost::trim(texture_name);
                boost::trim(texture_path);

                AssetsManager::addTexture(texture_name, texture_path);
            }

            f.close();
        }
        else {
            f.close();
            throw(std::invalid_argument(atlas_path));
        }
    }

    static sf::Texture& get_texture(const std::string& texture_name)
    {
        if (_instance._textures.find(texture_name) 
            != _instance._textures.end())
            return *_instance._textures.at(texture_name);
        else throw(NoSuchTextureException(texture_name));
    }

private:
    AssetsManager(const AssetsManager&){}
    AssetsManager() {}

    static AssetsManager _instance;
    std::map<std::string, TexturePtr > _textures;
};

#endif
