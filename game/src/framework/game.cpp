#include "framework/game.h"

#include<quill/Frontend.h>
#include<quill/LogMacros.h>
#include<quill/sinks/ConsoleSink.h>

Game::Game()
	:mWindow{ sf::VideoMode(640, 480), "SFML Application" },
	mPlayer{},
	mIsMovingUp{false},
	mIsMovingDown{false},
	mIsMovingLeft{false},
	mIsMovingRight{false},
	mMovement{0.f,0.f}
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
		/*
		if (event.type == sf::Event::Closed)
			mWindow.close();
		*/
		switch (event.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, true);
			break;
		}

	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W || key == sf::Keyboard::PageUp) {
		mIsMovingUp = isPressed;
		LOG_INFO(mlogger, "Move Up");
	}
	else if (key == sf::Keyboard::S|| key == sf::Keyboard::PageDown) {
		mIsMovingDown = isPressed;
		LOG_INFO(mlogger, "Move Down");
	}
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left) {
		mIsMovingLeft = isPressed;
		LOG_INFO(mlogger, "Move Left");
	}
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right) {
		mIsMovingRight = isPressed;
		LOG_INFO(mlogger, "Move Right");
	}
}

void Game::update() {
	if (mIsMovingUp) {
		mMovement.y -= 1.f;
	}

	if (mIsMovingDown) {
		mMovement.y += 1.f;
	}

	if (mIsMovingLeft) {
		mMovement.x += 1.f;
	}

	if (mIsMovingRight) {
		mMovement.x -= 1.f;
	}

	mPlayer.move(mMovement );
}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}
