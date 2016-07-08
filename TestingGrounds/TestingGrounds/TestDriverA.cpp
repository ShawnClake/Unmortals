#include "windowConsts.h"
#include "framerate.h"
#include <iostream>
#include "Player.h"
#include "Thread.h"
#include "PlatformA.h"
#include "Collision.h"

float operator*=(float& lhs, sth::Framerate& fr) {

	return fr.apply(lhs);

}

int main() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = sth::WindowConsts::aaLevels;

	sf::RenderWindow* window = sth::Thread::windowCreator(sf::Vector2i(sth::WindowConsts::mainGameW, sth::WindowConsts::mainGameH), settings);
	sth::Game game;

	sth::Object *platform1 = new sth::PlatformA(game.textureHandler, 50.f, 10.f);

	sth::Collision detection;

	if (detection.pointInRectangle(sth::xyfVector(124.f, 104.f), platform1))
		std::cout << "INSIDE" << std::endl;
	else
		std::cout << "OUTSIDE" << std::endl;

	char temp;

	std::cin >> temp;
	return 0;
}