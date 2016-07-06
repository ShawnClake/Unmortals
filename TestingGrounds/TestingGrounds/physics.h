#pragma once

#include "mathConsts.h"
#include <math.h>

namespace sth {

	class Physics {

	public:

		static float radToDec(float rad) {

			return rad * 180 / MathConsts::pi;

		}

		static float angularV(float tangentialV, float radius) {

			return radToDec(tangentialV / radius);

		}

		static float calcForce(float acceleration, float mass) {

			return mass * acceleration;

		}

		static float calcVFromForce(float time, float mass, float force) {

			return force * time / mass;

		}

		static float calcV(float time, float acceleration) {

			return time * acceleration;

		}

		static float calcWeight(float mass) {

			return mass * MathConsts::gravity;

		}

		static float calcNormForce(float mass, float appliedForce, float appliedAngle = 0) {

			return calcWeight(mass) - (appliedForce * sin(appliedAngle));

		}

		//Kinetic Friction
		static float calcKFriction(float mass, float appliedForce, float appliedAngle = 0) {

			return calcNormForce(mass, appliedForce, appliedAngle) * MathConsts::kineticFriction;

		}

		//Static Friction
		static float calcSFriction(float mass, float appliedForce, float appliedAngle = 0) {

			return calcNormForce(mass, appliedForce, appliedAngle) * MathConsts::staticFriction;

		}

	};

}

