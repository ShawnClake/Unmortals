#pragma once

#include "Object.h"
#include "mathConsts.h"

namespace sth {

	class Gravity {
	public:
		static void gravity(Object* e) {

			// All entities effected by gravity
			if (e->velocity.y != 0 && e->canFall) {

				float forceG = MathConsts::gravity;

				e->velocity.y += forceG;

			}
				
		}

	};

}