#pragma once

#include "Object.h"

namespace sth {

	class MaxSpeed {
	public:
		static void maxspeed(Object* e) {

			if (abs(e->velocity.x) > e->velocityMax.x) {

				if (e->velocity.x < 0)
					e->velocity.x = -e->velocityMax.x;
				else
					e->velocity.x = e->velocityMax.x;

			}

			if (abs(e->velocity.y) > e->velocityMax.y) {

				if (e->velocity.y < 0)
					e->velocity.y = -e->velocityMax.y;
				else
					e->velocity.y = e->velocityMax.y;

			}

		}

	};

}