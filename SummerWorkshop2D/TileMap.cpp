// @author Matt Kataryniak

#include <SFML\graphics.hpp>
#include "TileMap.h"


/**
 * @brief This attempts to load and populate the VertexArray used for the tilemap
 * @param tileset The name of the texture file to load
 * @param tileSize The size of the requested tile (x, y)
 * @param tiles An array of integers representing which tile from the tilesheet to load
 * @param width The number of tiles representing the width of the TileMap
 * @param height The number of tiles representing the height of the TileMap
 * @return true if the tilemap was loaded correctly, false if it was not
 */
bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	//Load the tileset texture from the specified file
	if (!m_tileset.loadFromFile(tileset))
		return false;

	//Resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	//Populate the vertex array, one quad per tile
	for (unsigned int i=0; i < width; ++i)
	{
		for (unsigned int j=0; j < height; ++j)
		{
			//Get the current tile number
			int tileNumber = tiles[i + j*width];

			//Find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			//Get a pointer to the quad of the current tile
			sf::Vertex* quad = &m_vertices[(i + j*width) * 4];

			//Define the four corners of the tile
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i+1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i+1) * tileSize.x, (j+1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j+1) * tileSize.y);

			//Define the four texture coordinates for the tile
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu+1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu+1) * tileSize.x, (tv+1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv+1) * tileSize.y);
		}
	}

	return true;
}

/**
	* @brief This will draw the completed TileMap
	* @param target The...
	* @param states The...
	* @return NULL
	*/
void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Apply the transform
	states.transform *= getTransform();

	//Apply the tileset texture
	states.texture = &m_tileset;

	//Draw the vertex array
	target.draw(m_vertices, states);
}
