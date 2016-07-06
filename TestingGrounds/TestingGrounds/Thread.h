#pragma once

#include <SFML\Graphics.hpp>
#include "Game.h"
#include "input.h"
#include "Frame.h"
#include "Draw.h"

namespace sth {

	class Thread {
	public:
		static sf::RenderWindow* windowCreator(const sf::Vector2i& dimensions, const sf::ContextSettings& settings) {

			return new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), "Gamez", sf::Style::Default, settings);

		}


		static bool GameLoop(Game& game, sf::RenderWindow& window) {

			Input* input = new Input();

			while (window.isOpen()) {

				
				//Frame::process(game, window);

				Frame::processEvents(game, window, input);

				game.fr.lap();	

				while (game.fr.accumulatorFull())
				{

					game.fr.adjustAccumulatorFrame();

					Frame::processEvents(game, window, input);

					Frame::update(game, window, *input);
					
				}
				
				Frame::initRender(game);

				Draw::draw(game, window);

			}

			delete input;

			return true;

		}

	};

}