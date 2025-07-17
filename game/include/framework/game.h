#pragma once
#include<SFML/Graphics.hpp>
#include<quill/Logger.h>

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	quill::Logger* mlogger;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;

	sf::Vector2f mMovement;


};