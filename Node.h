#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class Node
{
private:
	int _wall;
	bool _visited = 0;
	sf::RectangleShape _tile;
	int _parent[2];

public:
	Node(int x, int y);

	int getNodeType()const;
	bool getVisited()const;
	int getParent(int i)const;
	void setNodeType(const int type);
	void setVisited(const bool visited);
	void setParent(const int x, const int y);

	void draw(sf::RenderWindow &window);
};