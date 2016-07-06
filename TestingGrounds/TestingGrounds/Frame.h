#pragma once

#include "Game.h"
#include "input.h"

namespace sth {

	class Frame {

	public:
		static bool update(Game& game, sf::RenderWindow& window, Input& input) {
			

			for (auto e = game.objects.begin(); e != game.objects.end(); ++e) {

				(*e)->process(game.fr, input);
				
			}

			return true;

		}

		static bool initRender(Game& game) {

			// All entities flagged to draw are sent to the drawing buffer
			for (auto e = game.objects.begin(); e != game.objects.end(); ++e) {

				if ((*e)->model.toDraw)
					game.todraw.push_back((*e)->model);

			}

			return true;

		}

		static bool processEvents(Game& game, sf::RenderWindow& window, Input* input) {

			sf::Event event;
			while (window.pollEvent(event)) {

				if (event.type == sf::Event::Closed)
					window.close();
			}

			input->reset();

			input->getInput(window);

			return true;

		}

	};

}