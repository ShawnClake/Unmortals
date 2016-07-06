#pragma once

#include "Object.h"

namespace sth {

	class Boundings {
	public:
		virtual bool windowBottom(Object* e) = 0;
		virtual bool windowTop(Object* e) = 0;
		virtual bool windowLeft(Object* e) = 0;
		virtual bool windowRight(Object* e) = 0;

		bool inWindow(Object* e, bool forceInWindow = true) {

			if (e->model.isCircle()) {

				sf::Vector2f tmp = e->model.circle->getPosition();

				float x = tmp.x;
				float y = tmp.y;

				bool wasInBounds = true;

				//e->model.circle->setPosition(x, y);

				if (windowLeft(e)) {

					if (forceInWindow) {
						x = e->dimensions.r;
						e->velocity.x = 0;
					}

					wasInBounds = false;

				}

				if (windowRight(e)) {

					if (forceInWindow) {

						x = WindowConsts::mainGameW - e->dimensions.r;
						e->velocity.x = 0;

					}

					wasInBounds = false;

				}

				if (windowBottom(e)) {

					if (forceInWindow) {

						y = WindowConsts::mainGameH - e->dimensions.r;
						e->velocity.y = 0;

					}

				}

				e->model.circle->setPosition(x, y);

				return wasInBounds;

			}

		}


	};



}