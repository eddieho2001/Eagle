#include "framework/game.h"

#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>

Game::Game()
	:mWindow{ sf::VideoMode(640, 480), "SFML Application" },
	mPlayer{}
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);

	mlogger = quill::Frontend::create_or_get_logger("Game", quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1"));
	mlogger->set_immediate_flush(true);
}

void Game::run() {
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::update() {

}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}
