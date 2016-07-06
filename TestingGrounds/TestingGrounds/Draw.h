#pragma once

#include "Models.h"
#include "Game.h"

namespace sth {

	class Draw {

	public:

		static bool draw(Game& game, sf::RenderWindow& window) {

			window.clear();

			while (!game.todraw.empty()) {

				Models model = game.todraw.back();

				if (model.isCircle())
					window.draw(*model.circle);
				else if (model.isRect())
					window.draw(*model.rect);
				else if (model.isSprite())
					window.draw(*model.sprite);

				game.todraw.pop_back();
				
			}

			window.display();

			return true;
		}

	};

}