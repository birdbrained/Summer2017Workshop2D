// @author Matt Kataryniak

#include <SFML\graphics.hpp>

/**
 * @brief Consists of a VertexArray of tiles, and a Texture the TileMap is constructed from
 */
class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};
