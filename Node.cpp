#include "Node.h"

Node::Node(int x, int y)
{
	_tile.setSize(sf::Vector2f(24, 24));
	_tile.setPosition(sf::Vector2f(x * 24, y * 24));
	_tile.setOutlineThickness(2);
	_tile.setOutlineColor(sf::Color::Cyan);
	_tile.setFillColor(sf::Color::Black);
	_wall = 0;
}

int Node::getNodeType() const
{
	return _wall;
}

bool Node::getVisited() const
{
	return _visited;
}

int Node::getParent(int i) const
{
	return _parent[i];
}

void Node::setNodeType(const int type)
{
	_wall = type;
	if (_wall == 2)
		_visited = 1;
}

void Node::setVisited(const bool visited)
{
	_visited = visited;
}

void Node::setParent(const int x, const int y)
{
	_parent[0] = x;
	_parent[1] = y;
}

void Node::draw(sf::RenderWindow &window)
{
	switch (_wall)
	{
	case 0:
		_tile.setFillColor(sf::Color::Black);
		break;
	case 1:
		_tile.setFillColor(sf::Color::White);
		break;
	case 2:
		_tile.setFillColor(sf::Color::Green);
		break;
	case 3:
		_tile.setFillColor(sf::Color::Red);
		break;
	case 4:
		_tile.setFillColor(sf::Color::Yellow);
		break;
	}
	window.draw(_tile);
}