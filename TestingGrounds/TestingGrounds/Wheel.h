#pragma once

#include <iostream>
#include "Circle.h"
#include "Generic.h"

namespace sth {

	class Wheel : public Circle, public Generic {
	public:

		void initModel(const dimensions & dims, Models& model) {

			model.circle = new sf::CircleShape();

			model.circle->setRadius(dims.r);
			model.circle->setOrigin(dims.r, dims.r);
			model.circle->setPosition(WindowConsts::mainGameW / 2, WindowConsts::mainGameH - dims.r);

		}

		void initTexture(std::string filename, TextureHandler& th, Models& model) {

			model.circle->setTexture(th.getTexture(filename));

			initModelProperties();

		}

		void initModelProperties() {

			return;

		}

		virtual void move(Object* e, Framerate& fr) {

			if (e->model.isCircle()) {

				e->model.circle->move(fr * e->velocity.x, fr * e->velocity.y);

				if (inWindow(e, true) && e->canRotate) {

					e->model.circle->rotate(Physics::angularV(fr * e->velocity.x, e->dimensions.r));

				}

			}

		}

	};

}