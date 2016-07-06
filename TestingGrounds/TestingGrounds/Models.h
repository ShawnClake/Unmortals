#pragma once

#include "TextureHandler.h"

namespace sth {

	class Models {

	public:
		sf::CircleShape* circle;
		sf::RectangleShape* rect;
		sf::Sprite* sprite;
		bool toDraw;

		Models() {

			toDraw = true;

		}

		bool isSprite() {

			return sprite != nullptr;

		}

		bool isCircle() {

			return circle != nullptr;

		}

		bool isRect() {

			return rect != nullptr;

		}

	};

}