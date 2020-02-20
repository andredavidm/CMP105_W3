#include "Level.h"
using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	
	//circle
	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Green);

	xspeed = 600.f;
	yspeed = 600.f;
	
	//player
	player.setRadius(15);
	player.setPosition(100, 100);
	player.setFillColor(sf::Color::Red);

	xplayer = 200.f;
	yplayer = 200.f;
	
	acel = 1;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	//up and down
	if (input->isKeyDown(sf::Keyboard::W))
	{
		ydirection = -1;
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		ydirection = 1;
	}
	else
	{
		ydirection = 0;
	}
	//sideways
	if (input->isKeyDown(sf::Keyboard::A))
	{
		xdirection = -1;
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		xdirection = 1;
	}
	else
	{
		xdirection = 0;
	}


	if (input->isKeyDown(sf::Keyboard::X))
	{
		acel = acel + 0.01;
	}
	if (input->isKeyDown(sf::Keyboard::Z) )
	{
		acel = acel - 0.01;
		if (acel < 0)
		{
			acel = 0;
		}
	}

}

// Update game objects
void Level::update(float dt)
{
	
	//get window size
	sf::Vector2u pos = window->getSize();
	
	
	player.move(xplayer * dt * xdirection, yplayer * dt * ydirection);
	

	
	
	//circle movement
	sf::Vector2f position = circle.getPosition();

	circle.move(xspeed * acel * dt, yspeed * acel * dt);

	if (position.y >= pos.y)
	{
		yspeed = -200.f ;
	
	}
	if (position.y <=0 )
	{
		yspeed = 200.f ;

	}
	if (position.x >= pos.x)
	{
		xspeed = -200.f ;

	}
	if (position.x <= 0)
	{
		xspeed = 200.f ;

	}


	
	//cout << position.x << endl;
	cout << acel << endl;
	

}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(circle);
	window->draw(player);
	
	
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}