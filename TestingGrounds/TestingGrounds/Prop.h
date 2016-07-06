#pragma once

#include "Object.h"
#include <iostream>
#include "Friction.h"
#include "Gravity.h"
#include "MaxSpeed.h"

namespace sth {

	class Prop : public Object {

		void move(Object* e, Framerate& fr) {

			std::cout << "PROP CLASS" << std::endl;

		}

		void inputHandler(const Input& input) {

			return;

		}

		void process(Framerate& fr, const Input& input) {

			//std::cout << "HERE" << std::endl;
			if (canFall)
				Gravity::gravity(this);

			if (canFriction)
				Friction::friction(this, input);

			if (hasMaxspeed)
				MaxSpeed::maxspeed(this);

			if (canMove)
				move(this, fr);

		}

		~Prop() {



		}



	};



}