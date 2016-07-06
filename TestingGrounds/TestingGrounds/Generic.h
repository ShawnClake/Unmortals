#pragma once

#include "physics.h"

namespace sth {

	class Generic {
	public:
		virtual void move(Object* e, Framerate& fr) = 0;
		virtual void initModel(const float radius, Models& model) = 0;
		virtual void initTexture(std::string filename, TextureHandler& th, Models& model) = 0;
		virtual void initModelProperties() = 0;



	};

}