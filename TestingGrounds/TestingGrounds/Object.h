#pragma once

#include "Models.h"
#include "input.h"
#include "framerate.h"

namespace sth {

	struct xyfVector {

		float x = 0;
		float y = 0;

	};

	struct dimensions {

		float x = 0; // Width
		float y = 0; // Height
		float z = 0; // Depth
		float r = 0; // Radius

	};

	class Object {
	public:


		xyfVector velocity; // x,y velocity
		xyfVector acceleration; // x,y acceleration
		xyfVector velocityMax; // x,y max velocity
		xyfVector accelerationMax; // x,y max acceleration
		dimensions dimensions; // x-width, y-height, z-depth, r-radius dimensions

		Models model;

		float
			mass = 0; // Mass of object. (NOT WEIGHT)

		bool canFall, // Effected by gravity.
			canFriction, // Effected by friction
			collidable, // Collidable object via bounding box
			canRotate, // Object can rotate
			canMove, // Object can move and is not stuck in place
			hasMaxspeed; // Object has a maximum speed.


		virtual void inputHandler(const Input& input) = 0;

		virtual void move(Object* e, Framerate& fr) = 0;

		virtual void process(Framerate& fr, const Input& input) = 0;

		virtual ~Object() {
		
		};

		virtual bool isInteractive() = 0;


	};

}