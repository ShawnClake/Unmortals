#pragma once

#include "Object.h"
#include <iostream>
#include "Friction.h"
#include "Gravity.h"
#include "MaxSpeed.h"

namespace sth {

	class Entity : public Object {
	public:

		float
			jumpAcceleration = 0; // vertical acceleration when jumping

		bool
			isJumping, // Whether the entity is in the process of jumping
			canJump, // Whether the entity is able to jump
			interactive; // Whether the entity is interactive

		void move(Object* e, Framerate& fr) {

			std::cout << "ENTITY CLASS" << std::endl;

		}

		void inputHandler(const Input& input) {

			return;

		}

		void process(Framerate& fr, const Input& input) {

			//std::cout << "HERE" << std::endl;

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

		}

		bool isInteractive() {

			return interactive;

		}

		~Entity() {



		}



	};

}