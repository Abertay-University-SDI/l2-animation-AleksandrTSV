#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	/*m_snake.setRadius(20);
	m_snake.setPosition({ 50, 50 });
	m_snake.setFillColor(sf::Color::Green);*/

	if (!m_sheep_texture.loadFromFile("gfx/sheep_sheet.png"))
		std::cerr << "Unable to load file: gfx/sheep_sheet.png";
	m_sheep.setTexture(&m_sheep_texture);
	m_sheep.setSize({ 64,64 });

	for (int i = 0; i < 20; i++)
	{
		int row = i / 3;
		int column = i % 8;

		sf::IntRect texture_rect({column * 64, row * 64 }, { 64,64 });
		m_sheepIntRect.push_back(texture_rect);
	}

	m_sheep.setTextureRect(m_sheepIntRect[0]);
	m_sheep.setInput(&m_input);
	m_sheep.setWindow(&hwnd);
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_gameOver) return;
	m_sheep.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	if (m_gameOver) return;
	m_sheep.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	//m_window.draw(m_snake);
	m_window.draw(m_sheep);
	endDraw();
}