#pragma once

#include "Entity.h"
#include "Wheel.h"
#include <iostream>

namespace sth {

	class Player : public Entity, public Wheel {
	public:

		Player() {}

		Player(TextureHandler& textureHandler, float radius = 0) {

			dimensions.r = radius;

			mass = .5f;

			velocity.x = 0;
			velocity.y = 0;

			acceleration.x = 1.4f;
			acceleration.y = 0.f;

			jumpAcceleration = 150.f;

			accelerationMax.x = 1200.f;
			accelerationMax.y = 1200.f;

			velocityMax.x = 227.8f;
			velocityMax.y = 2200.f;

			canFall = true;
			canFriction = true;
			collidable = true;
			isJumping = false;
			canJump = true;
			interactive = true;
			canRotate = true;
			canMove = true;
			hasMaxspeed = true;

			initModel(radius, model);

			initTexture("rock1.jpg", textureHandler, model);

		}

		void initModelProperties() {

			model.circle->setOutlineColor(sf::Color::White);
			model.circle->setOutlineThickness(1.f);

		}

		void move(Object* e, Framerate& fr) {

			std::cout << "PLAYER CLASS" << std::endl;
			Wheel::move(e, fr);
			

		}

		void process(Framerate& fr, const Input& input) {

			std::cout << "HERE" << std::endl;

			if (interactive)
				inputHandler(input);

			if (canFall)
				Gravity::gravity(this);

			if (canFriction)
				Friction::friction(this, input);

			if (hasMaxspeed)
				MaxSpeed::maxspeed(this);

			if (canMove)
				move(this, fr);

			if (velocity.y == 0)
				isJumping = false;

		}

		void inputHandler(const Input& input) {
			
			if (input.a) {

				if (velocity.x > 0)
					velocity.x = 0;
				velocity.x -= acceleration.x;

			}

			if (input.d) {

				if (input.d) {

					if (velocity.x < 0)
						velocity.x = 0;
					velocity.x += acceleration.x;

				}

			}

			if (input.space) {

				if (velocity.y == 0 && !isJumping && canJump) {

					velocity.y -= jumpAcceleration;
					isJumping = true;

				}


			}


		}

	};

}