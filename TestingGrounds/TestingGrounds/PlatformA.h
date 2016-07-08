#pragma once
#include "Prop.h"
#include "FloatingPlatform.h"

namespace sth {

	class PlatformA : public Prop, public FloatingPlatform {
	public: 
		PlatformA() {}

		PlatformA(TextureHandler& textureHandler, float dimx, float dimy) {

			dimensions.x = dimx;
			dimensions.y = dimy;

			velocity.x = 0;
			velocity.y = 0;

			acceleration.x = 0.f;
			acceleration.y = 0.f;

			accelerationMax.x = 1200.f;
			accelerationMax.y = 1200.f;

			velocityMax.x = 227.8f;
			velocityMax.y = 2200.f;

			canFall = false;
			canFriction = true;
			collidable = true;
			canRotate = false;
			canMove = false;
			hasMaxspeed = true;

			initModel(dimensions, model);

			initTexture("rock2.jpg", textureHandler, model);

		}

		void initModelProperties() {

			model.rect->setOutlineColor(sf::Color::White);
			model.rect->setOutlineThickness(.2f);

		}



	};



}