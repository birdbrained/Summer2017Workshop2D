// @author Matt Kataryniak

#include <SFML\graphics.hpp>
#include "Collision.h"

/**
 * @brief Takes a Vector2f point and checks to see if it is inside of the FloatRect
 * @param t The point to test
 * @param A The FloatRect to test
 * @return 1 if point is inside FloatRect, 0 if the point is not
 */
int PointInAABB(sf::Vector2f t, sf::FloatRect A)
{
	if (t.x >= A.left && t.x <= A.left + A.width && t.y >= A.top && t.y <= A.top + A.height)
		return 1;
	return 0;
}

/**
 * @brief Checks to see if two FloatRects have collided with each other
 * @param A The first FloatRect
 * @param B The second FloatRect
 * @return 1 if FloatRects are colliding, 0 if they are not
 */
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