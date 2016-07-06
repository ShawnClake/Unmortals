#include "windowConsts.h"
#include "framerate.h"
#include <iostream>
#include "Player.h"
#include "Thread.h"

float operator*=(float& lhs, sth::Framerate& fr) {

	return fr.apply(lhs);

}

int main() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = sth::WindowConsts::aaLevels;

	sf::RenderWindow* window = sth::Thread::windowCreator(sf::Vector2i(sth::WindowConsts::mainGameW, sth::WindowConsts::mainGameH), settings);
	sth::Game game;

	sth::Object *player = new sth::Player(game.textureHandler, 10.f);

	game.objects.push_back(player);

	return sth::Thread::GameLoop(game, *window);

	/*sth::Framerate fr;
	float cheese = 60.f;

	fr.lap();

	for (int i = 0; i < 1000; i++) {
		std::cout << fr * cheese << std::endl;
		fr.lap();
	}

	//char keepOpen = ' ';

	//sth::Object *player = new sth::Player();

	//std::cin >> keepOpen;*/

	return 0;
}