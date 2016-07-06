#pragma once
#include <SFML\System.hpp>
#include "mathConsts.h"

namespace sth {

	class Framerate {

	public:

		sf::Time elapsed = sf::Time::Zero;

		sf::Clock clock;

		sf::Time accumulator = sf::Time::Zero;

		const sf::Time perFrame = sf::seconds(MathConsts::hz60);

		float apply(float value) {

			return value * perFrame.asSeconds();

		}

		void lap() {

			elapsed = clock.restart();
			accumulator += elapsed;

		}

		bool accumulatorFull() {

			return accumulator > perFrame;

		}

		void adjustAccumulatorFrame() {

			accumulator -= perFrame;

		}

		float operator*(float& value) {

			return apply(value);

		}

		float operator*=(float& value) {

			return apply(value);

		}

	};

}

