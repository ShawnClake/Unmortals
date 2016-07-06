#pragma once

#include <SFML\Graphics.hpp>
#include <string>

namespace sth {

	namespace TextureConsts {

		const static std::string texturePath = "assets/textures/";

	}

	class TextureLoader {
	public:
		static sf::Texture* loadTexture(std::string filename, sf::Vector2i topleft, sf::Vector2i dimensions) {

			sf::Texture* texture = new sf::Texture();

			if (texture->loadFromFile(TextureConsts::texturePath + filename, sf::IntRect(topleft, dimensions))) {

				texture->setSmooth(true);

				return texture;

			}

			return nullptr;

		}

		static void deleteTexture(sf::Texture* texture) {

			delete texture;

		}

	};


}