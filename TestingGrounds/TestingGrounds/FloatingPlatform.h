#pragma once

#include "Generic.h"
#include "Rectangle.h"


namespace sth {

	class FloatingPlatform : public Generic, public Rectangle {

		void initModel(const dimensions & dimensions, Models& model) {

			model.rect = new sf::RectangleShape();

			model.rect->setSize(sf::Vector2f(dimensions.x, dimensions.y));
			model.rect->setOrigin(dimensions.x / 2, dimensions.y / 2);
			model.rect->setPosition(WindowConsts::mainGameW / 1.4, WindowConsts::mainGameH - dimensions.y);

		}

		void initTexture(std::string filename, TextureHandler& th, Models& model) {

			model.rect->setTexture(th.getTexture(filename));

			initModelProperties();

		}

		void initModelProperties() {

			return;

		}

		virtual void move(Object* e, Framerate& fr) {

			if (e->model.isRect()) {

				e->model.rect->move(fr * e->velocity.x, fr * e->velocity.y);

				if (inWindow(e, true) && e->canRotate) {

					e->model.rect->rotate(Physics::angularV(fr * e->velocity.x, e->dimensions.r));

				}

			}

		}




	};



}