#pragma once

#include <unordered_map>
#include "textureLoader.h"

namespace sth {

	class TextureHandler : public TextureLoader {

	private:
		typedef std::pair<std::string, sf::Texture*> texture;

	public:
		std::unordered_map<std::string, sf::Texture*> textures;

		sf::Texture* getTexture(std::string filename) {

			textures.insert(texture(filename, loadTexture(filename, sf::Vector2i(0, 0), sf::Vector2i(512, 512))));
			
			return textures.at(filename);

		}

		void clear() {


			textures.clear();


		}

		~TextureHandler() {

			clear();


		}

	};

}