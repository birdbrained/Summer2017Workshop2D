// @author Matt Kataryniak

#include <SFML\graphics.hpp>

/**
 * @brief The maximum number of frames a single animation can have
 */
#define MAX_FRAMES_PER_ANIMATION 11

/**
 * @brief This is an animation structure
 */
struct Animation
{
	int count; /**< Number of frames the animation has; it can be less than MAX_FRAMES_PER_ANIMATION, but not greater */
	sf::IntRect frames[MAX_FRAMES_PER_ANIMATION]; /**< The IntRect of where the frames are located */
	int times[MAX_FRAMES_PER_ANIMATION]; /**< How fast the sprite should animate (Frame Rate) */
};
