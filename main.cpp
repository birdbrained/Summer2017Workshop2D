/**
 * @author Matt Kataryniak
 */
#include <SFML\graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "SummerWorkshop2D\Animation.h"
//#include "SummerWorkshop2D\Collision.cpp"

#define SECONDS_PER_FRAME 16
//#define MAX_FRAMES_PER_ANIMATION 11


int PointInAABB(sf::Vector2f t, sf::FloatRect A)
{
	if (t.x >= A.left && t.x <= A.left + A.width && t.y >= A.top && t.y <= A.top + A.height)
		return 1;
	return 0;
}

int AABBinAABB(sf::FloatRect A, sf::FloatRect B)
{
	if (!PointInAABB(sf::Vector2f(A.left, A.top), B))
		if (!PointInAABB(sf::Vector2f(A.left + A.width, A.top), B))
			if (!PointInAABB(sf::Vector2f(A.left, A.top + A.height), B))
				if(!PointInAABB(sf::Vector2f(A.left + A.width, A.top + A.height), B))
					if (!PointInAABB(sf::Vector2f(B.left, B.top), A))
						if (!PointInAABB(sf::Vector2f(B.left + B.width, B.top), A))
							if(!PointInAABB(sf::Vector2f(B.left, B.top + B.height), A))
								if (!PointInAABB(sf::Vector2f(B.left + B.width, B.top + B.height), A))
									return 0;
	return 1;

}

/*int PointInAABB(sf::Vector2f t, sf::Sprite A)
{
	if (t.x >= A.getPosition().x && t.x <= A.getPosition().x + A.getTextureRect().width
		&& t.y >= A.getPosition().y && t.y <= A.getPosition().y + A.getTextureRect().height)
		return 1;
	return 0;
}*?

/**
 * @brief This takes input and that's about it
 * @return NULL
 */
void Input()
{
	sf::Event myEvent;
	
}

/**
 * @brief This updates the world
 * @return NULL
 */
void Update()
{

}

/**
 * @brief This draws shit
 * @return NULL
 */
void DrawShit()
{
	
}

/*
 * @brief Creates something that can be animated
 *
/*struct Animation
{
	int count; //number of frames
	sf::IntRect frames[MAX_FRAMES_PER_ANIMATION]; //Where frames are located
	int times[MAX_FRAMES_PER_ANIMATION]; //timing
};*/

/**
 * @brief The the heart of operations
 * @param argc Count of arguments
 * @param argv Array of character arguments
 * @return 0 if good, 1 if error
 */
int main(int argc, char ** argv)
{
	//create the actual window
	sf::RenderWindow window(sf::VideoMode(800, 600), "da fuck"); //sf::Style::Fullscreen
	//create a circle object
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(30, 50);

	sf::CircleShape point(5);
	point.setFillColor(sf::Color::Black);
	point.setPosition(500, 10);

	//seeds the random number based on the current system time
	srand(time(NULL));
	//std::vector<sf::CircleShape*> circleArr;
	//sf::CircleShape *circleArr[10];
	sf::CircleShape circleArr[10];
	for (int i=0; i<10; i++)
	{
		/*
		//My ugly pointer shit
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


	// Loading assets, this is all initilzation
	sf::Clock clock;
	sf::Texture texture;
	sf::IntRect rectSource(0, 0, 46, 46); //left, top, width, height
	texture.loadFromFile("Sprites/idle.png");
	sf::Sprite sprite(texture);
	Animation animation;
	sprite.setScale(3, 3);
	//sprite.setTextureRect(rectSource);

	sf::Texture texture2;
	sf::IntRect rectSource2(00, 0, 46, 46);
	texture2.loadFromFile("Sprites/Dead2.png");
	sf::Sprite sprite2(texture2);
	sprite2.setScale(3, 3);
	sprite2.setPosition(600.0f, 0.0f);
	
	//int x, y;
	animation.count = 11;
	if (animation.count > MAX_FRAMES_PER_ANIMATION)
	{
		animation.count = MAX_FRAMES_PER_ANIMATION;
		printf("Animation frame count is greater than MAX_FRAMES_PER_ANIMATION, lowering variable count to MAX_FRAMES_PER_ANIMATION\n");
	}
	for (int i = 0; i < 11; i++)
	{
		animation.frames[i] = rectSource;
		animation.times[i] = 100;
		rectSource.left += 46;
	}
	//x = y = 0;
	int frame = 0;
	int frameTimer = animation.times[0];
	FILE * file;
	file = fopen("output.txt","w");

	sf::Vector2f myVect;
	myVect.x = 500;
	myVect.y = 1;

	//Collision?
	bool collide = false;

	//the game loop
	while (window.isOpen())
	{
		// ***DO NOT LOAD ASSETS IN THE WHILE LOOP!!!!!!!!!***

		sf::Event myEvent; //delcare an event
		//x = (x + 1) % 128;
		//y = (y + 1) % 128;
		//rectSource.left = x;
		//rectSource.top = y;
		//sprite.setTextureRect(rectSource);
		//sprite.setPosition(sf::Vector2f(x, y));

		if (window.pollEvent(myEvent)) //poll to see if an event happened, and store it in the variable
		{
			switch (myEvent.type)
			{
			case sf::Event::KeyPressed:
				if (myEvent.key.code == sf::Keyboard::F)
				{
					printf("F was pressed, also, fugg' off.\n");
					//1. When you hold down a key, it is considered pressed until you release it
					//2. 1st half second you press and hold a key, it doesn't count (STICKY KEYSSS!!!!)
				}
				else if (myEvent.key.code == sf::Keyboard::W)
				{
					printf("W was pressed, also, some insult that starts with W!\n");
					sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 5);
				}
				else if (myEvent.key.code == sf::Keyboard::A)
				{
					printf("A was pressed, also, some insult that starts with A!\n");
					sprite.setPosition(sprite.getPosition().x - 5, sprite.getPosition().y);
				}
				else if (myEvent.key.code == sf::Keyboard::S)
				{
					printf("S was pressed, also, some insult that starts with S!\n");
					sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 5);
				}
				else if (myEvent.key.code == sf::Keyboard::D)
				{
					printf("D was pressed, also, some insult that starts with D!\n");
					sprite.setPosition(sprite.getPosition().x + 5, sprite.getPosition().y);
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		//DRAW SHIT!!
		window.clear(sf::Color::Cyan); //clears the buffer (also added background color)
		window.draw(circle); //puts object on the buffer
		window.draw(point);
		/*for (auto& obj : circleArr)
		{
			window.draw(obj);
		}*/
		for (sf::CircleShape c : circleArr)
			window.draw(c);
		window.draw(sprite);
		window.draw(sprite2);
		window.display(); //shows the fucking buffer

		//Clock shit, pretty much a deltaTime
		if (clock.getElapsedTime().asMilliseconds() < SECONDS_PER_FRAME)
		{
			sf::sleep(sf::milliseconds(SECONDS_PER_FRAME - clock.getElapsedTime().asMilliseconds()));
		}

		frameTimer -= clock.getElapsedTime().asMilliseconds();
		fprintf(file, "FrameTimer: %d\n", frameTimer);
		if (frameTimer <= 0)
		{
			fprintf(file, "Passed test!\n");
			frame = (frame + 1) % 11;
			//frameTimer = 100;
			frameTimer = animation.times[frame];
		}
		//rectSource.left = frame * 46;
		//sprite.setTextureRect(rectSource);
		sprite.setTextureRect(animation.frames[frame]);
		clock.restart();

		//Move the two sprites towards each other. So what if it's bad, meeeeyhh.
		if (!collide)
		{
			sprite.setPosition(sprite.getPosition().x + 5.0f, sprite.getPosition().y);
			sprite2.setPosition(sprite2.getPosition().x - 5.0f, sprite2.getPosition().y);
		}

		//Test a point... lets say 500, 100 (declared above)
		//printf("sprite x: %d\n", sprite.getPosition().x);
		if (PointInAABB(myVect, sprite.getGlobalBounds()))
			printf("Hit the point!\n");

		//Ok, now test to see if the two sprites have collided with each other
		if (AABBinAABB(sprite.getGlobalBounds(), sprite2.getGlobalBounds()))
			collide = true;
		else
			collide = false;
	}

	fclose(file);
	return 0;
}
