#include <SFML\graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <time.h>

int main(int argc, char ** argv)
{
	//create the actual window
	sf::RenderWindow window(sf::VideoMode(800, 600), "da fuck"); //sf::Style::Fullscreen
	//create a circle object
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(30, 50);

	srand(time(NULL));
	//std::vector<sf::CircleShape*> circleArr;
	//sf::CircleShape *circleArr[10];
	sf::CircleShape circleArr[10];
	for (int i=0; i<10; i++)
	{
		/*
		circleArr[i] = new sf::CircleShape(200);
		circleArr[i]->setRadius((float)(rand() % 101));
		sf::Color randomColor(rand() % 256, rand() % 256, rand() % 256);
		circleArr[i]->setFillColor(randomColor);
		circleArr[i]->setPosition((float)(rand() % 600), (float)(rand() % 300));
		*/
		circleArr[i].setRadius((float)(rand() % 101));
		sf::Color randomColor(rand() % 256, rand() % 256, rand() % 256);
		circleArr[i].setFillColor(randomColor);
		circleArr[i].setPosition((float)(rand() % 600), (float)(rand() % 300));
	}

	//the game loop
	while (window.isOpen())
	{
		sf::Event myEvent; //delcare an event
		if (window.pollEvent(myEvent)) //poll to see if an event happened, and store it in the variable
		{
			switch (myEvent.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}

			//DRAW SHIT!!
			window.clear();			//clears the buffer
			window.draw(circle);	//puts object on the buffer
			/*for (auto& obj : circleArr)
			{
				window.draw(obj);
			}*/
			for (sf::CircleShape c : circleArr)
				window.draw(c);
			window.display();		//shows the fucking buffer
		}
	}

	return 0;
}

/*
Stuff you do not do in C++ that C requires:
	
*/