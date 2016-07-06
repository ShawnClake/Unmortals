#pragma once

#include "Object.h"
#include "physics.h"
#include "input.h"

namespace sth {

	class Friction {
	public:
		static void friction(Object * e, const Input& input) {

			// All entites effected by friction
			if (e->canFriction) {

				float friction = 1;

				if (e->isInteractive() && (input.a || input.d))
					friction = Physics::calcKFriction(e->mass, e->mass * e->acceleration.x);
				else
					friction = Physics::calcKFriction(e->mass, 0);

				if (abs(e->velocity.x) - friction > 0) {
					if (e->velocity.x > 0)
						e->velocity.x -= friction;
					else if (e->velocity.x < 0)
						e->velocity.x += friction;

					/*if (abs(e->xV) - friction < 0)
					if(e->controllable && (!input.a && !input.d))
					e->xV = 0;
					else if(!e->controllable)
					e->xV = 0;*/

				}
				else {

					e->velocity.x = 0;

				}

			}

		}

	};

}