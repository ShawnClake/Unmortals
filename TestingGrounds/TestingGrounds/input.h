#pragma once

#include <SFML\Graphics.hpp>
#include "windowConsts.h"

namespace sth {

	class Input {

	public:

		bool w = false;
		bool s = false;
		bool a = false;
		bool d = false;
		bool space = false;
		bool leftclick = false;
		sf::Vector2i position = sf::Vector2i(0, 0);

		sf::Vector2i mouseCoords(const sf::RenderWindow & window) {

			sf::Vector2i coords = sf::Mouse::getPosition(window);

			if (coords.x < 0)
				coords.x = 0;
			if (coords.y < 0)
				coords.y = 0;
			if (coords.x > WindowConsts::mainGameW)
				coords.x = WindowConsts::mainGameW;
			if (coords.y > WindowConsts::mainGameH)
				coords.y = WindowConsts::mainGameH;

			return coords;

		}

		void reset() {

			w = false;
			s = false;
			a = false;
			d = false;
			space = false;
			leftclick = false;
			position = sf::Vector2i(0, 0);

		}

		Input* getInput(const sf::RenderWindow & window) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				a = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				d = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				s = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				w = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				space = true;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				leftclick = true;

			position = mouseCoords(window);

			return this;

		}

	};

}