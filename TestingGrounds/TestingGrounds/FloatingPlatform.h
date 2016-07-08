#pragma once

#include "Generic.h"
#include "Rectangle.h"


namespace sth {

	class FloatingPlatform : public Rectangle, public Generic {
	public:
		void initModel(const dimensions & dims, Models& model) {

			model.rect = new sf::RectangleShape();

			model.rect->setSize(sf::Vector2f(dims.x, dims.y));
			model.rect->setOrigin(dims.x / 2, dims.y / 2);
			model.rect->setPosition( 100, 100 );

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