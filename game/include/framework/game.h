#pragma once
#include<SFML/Graphics.hpp>
#include<quill/Logger.h>

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	quill::Logger* mlogger;

};