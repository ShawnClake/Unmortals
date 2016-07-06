#pragma once

#include <vector>
#include "Models.h"
#include "Object.h"
#include "TextureHandler.h"
#include "framerate.h"

namespace sth {

	class Game {

	public:
		std::vector<Models> todraw;
		std::vector<Object*> objects;

		TextureHandler textureHandler;
		Framerate fr;
		//std::vector<Prop> props;

	};

}