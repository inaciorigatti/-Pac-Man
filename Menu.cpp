#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		std::cout << "Nao leu a fonte" << std::endl;
	}

    // Título
    title.setFont(font);
    title.setFillColor(sf::Color::Yellow);
    title.setCharacterSize(60);
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
    title.setString("Pac-man");
    title.setPosition(
        (width - title.getGlobalBounds().width) / 2, height / 8
    );

    // Itens do menu centralizados resolucao 1280x920
    menu[0].setFont(font);
    menu[0].setCharacterSize(24);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Jogar");
    menu[0].setPosition( (width - menu[0].getGlobalBounds().width) / 2, height / 5 );

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Ranking");
    menu[1].setPosition( (width - menu[1].getGlobalBounds().width) / 2, height / 3 );

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Sobre");
    menu[2].setPosition( (width - menu[2].getGlobalBounds().width) / 2, height / 2 );

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Sair");
    menu[3].setPosition( (width - menu[3].getGlobalBounds().width) / 2, height * (2.0f / 3.0f) );

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}