#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Menu");

	sf::Font font;

	if (!font.loadFromFile("arial.ttf"))
	{
		// handle error
	}

	sf::Text text0;
	text0.setFont(font);
	text0.setString("Save Me IF You Can!!!");
	text0.setFillColor(sf::Color::White);
	text0.setCharacterSize(150);
	text0.setPosition(200, 50);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
					{

						sf::RenderWindow window(sf::VideoMode(1500, 850), "Help");

						sf::Font font;

						if (!font.loadFromFile("arial.ttf"))
						{
							// handle error
						}

						sf::Text text1;
						text1.setFont(font);
						text1.setString("How to Play the Game");
						text1.setFillColor(sf::Color::White);
						text1.setCharacterSize(80);
						text1.setPosition(400, 20);


						sf::Text text2;
						text2.setFont(font);
						text2.setString("The Game is Very simple. You can either play with Computer or With your Friends. Your mission is to save\n the man.Firstly you have to play scissor paper rock with friends or computer.\n when you loose a body part of your man appears and slowly after 6 more times he fully appears and \nis hanged and you loose the game. \nOur mission is to save the man from hanging.\n\nControls::::\n\nA------------------->Scissor\nS---------------->Paper\nD--------------->Rock\n\nNum Pad 1-------------->Scissor\nNum Pad 2------------->Paper\nNum Pad 3------------->Rock\n\n\n\nPress Enter to Exit.");
						text2.setFillColor(sf::Color::Red);
						text2.setCharacterSize(30);
						text2.setPosition(50, 160);



						while (window.isOpen())
						{
							sf::Event event;

							while (window.pollEvent(event))
							{
								switch (event.type)
								{
								case sf::Event::Closed:
									window.close();

									break;
								}
							}

							window.clear();
							window.draw(text1);
							window.draw(text2);

							window.display();
						}
					}
					break;

					case 3:
					{
				
							sf::RenderWindow window(sf::VideoMode(1500, 850), "About Developers");

							sf::Font font;

							if (!font.loadFromFile("arial.ttf"))
							{
								// handle error
							}

							sf::Text text1;
							text1.setFont(font);
							text1.setString("Developers");
							text1.setFillColor(sf::Color::White);
							text1.setCharacterSize(80);
							text1.setPosition(650, 20);


							sf::Text text2;
							text2.setFont(font);
							text2.setString("Ashish Pokhrel (38)\n\n Dinesh Poudel (39)\n\n Prashant Bhatta (09) \n\nBishal K.C. (22)\n\n\n\n\nPress Enter to Exit.");
							text2.setFillColor(sf::Color::Red);
							text2.setCharacterSize(40);
							text2.setPosition(50, 160);

							

							while (window.isOpen())
							{
								sf::Event event;

								while (window.pollEvent(event))
								{
									switch (event.type)
									{
									case sf::Event::Closed:
										window.close();

										break;
									}
								}

								window.clear();
								window.draw(text1);
								window.draw(text2);

								window.display();
							}
						}
						break;
					case 4:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		window.draw(text0);
		

		menu.draw(window);

		window.display();
	}
}