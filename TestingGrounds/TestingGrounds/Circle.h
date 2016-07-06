#pragma once

#include "Boundings.h"
#include "windowConsts.h"

namespace sth {

	class Circle : public Boundings {

		bool windowRight(Object* e) {

			return e->model.circle->getPosition().x > WindowConsts::mainGameW - e->dimensions.r;

		}

		bool windowLeft(Object* e) {

			return e->model.circle->getPosition().x < e->dimensions.r;

		}

		bool windowBottom(Object* e) {

			return e->model.circle->getPosition().y > WindowConsts::mainGameH - e->dimensions.r;

		}

		bool windowTop(Object* e) {

			return e->model.circle->getPosition().y < e->dimensions.r;

		}

	};

}