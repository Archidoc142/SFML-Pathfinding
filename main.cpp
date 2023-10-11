#include <SFML/Graphics.hpp>
#include "Node.h"

void main()
{
    sf::RenderWindow window(sf::VideoMode(720, 720), "PathFinding");
    sf::Clock clock;
    sf::Time time;
    sf::Mouse mouse;
    std::vector< std::vector<Node> > tileMap;

    int cellX;
    int cellY;
    int cellXB;
    int cellYB;
    int cellXA;
    int cellYA;

    for (int x = 0; x < 30; x++)
    {
        tileMap.push_back(std::vector<Node>());

        for (int y = 0; y < 30; y++)
        {
            tileMap[x].push_back(Node(x, y));           
        }
    }

    while (window.isOpen())
    {
        sf::Event event;

        cellX = floor(mouse.getPosition(window).x / 24);
        cellY = floor(mouse.getPosition(window).y / 24);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            tileMap[cellX][cellY].setNodeType(2);
            cellXA = cellX;
            cellYA = cellY;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            tileMap[cellX][cellY].setNodeType(3);
            cellXB = cellX;
            cellYB = cellY;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            while (!tileMap[cellXB][cellYB].getVisited())
            {
                for (int x = 0; x < 30; x++)
                {
                    for (int y = 0; y < 30; y++)
                    {
                        if (tileMap[x][y].getVisited())
                        {
                            if (tileMap[x + 1][y].getNodeType() != 1 && !tileMap[x + 1][y].getVisited() && x < 28)
                            {
                                tileMap[x + 1][y].setVisited(1);
                                tileMap[x + 1][y].setParent(x, y);
                            }
                            if (tileMap[x - 1][y].getNodeType() != 1 && !tileMap[x - 1][y].getVisited() && x > 1)
                            {
                                tileMap[x - 1][y].setVisited(1);
                                tileMap[x - 1][y].setParent(x, y);
                            }
                            if (tileMap[x][y + 1].getNodeType() != 1 && !tileMap[x][y + 1].getVisited() && y < 28)
                            {
                                tileMap[x][y + 1].setVisited(1);
                                tileMap[x][y + 1].setParent(x, y);
                            }
                            if (tileMap[x][y - 1].getNodeType() != 1 && !tileMap[x][y - 1].getVisited() && y > 1)
                            {
                                tileMap[x][y - 1].setVisited(1);
                                tileMap[x][y - 1].setParent(x, y);
                            }
                        }
                    }
                }
            }
            int checkCellX = tileMap[cellXB][cellYB].getParent(0);
            int checkCellY = tileMap[cellXB][cellYB].getParent(1);
            int temp;

            while (tileMap[cellXA][cellYA].getNodeType() != 4)
            {
                tileMap[checkCellX][checkCellY].setNodeType(4);
                temp = checkCellX;
                checkCellX = tileMap[checkCellX][checkCellY].getParent(0);
                checkCellY = tileMap[temp][checkCellY].getParent(1);
            }
            tileMap[cellXA][cellYA].setNodeType(2);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            tileMap[cellX][cellY].setNodeType(1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
            tileMap[cellX][cellY].setNodeType(0);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
            for (int x = 0; x < 30; x++)
                for (int y = 0; y < 30; y++)
                {
                    tileMap[x][y].setVisited(0);
                    if (tileMap[x][y].getNodeType() == 4 || tileMap[x][y].getNodeType() == 3 || tileMap[x][y].getNodeType() == 2)
                        tileMap[x][y].setNodeType(0);
                }

        time = clock.getElapsedTime();
        if (time.asMilliseconds() >= 100.0f)
        {
            window.display();

            for (int y = 0; y < 30; y++)
            {
                for (int x = 0; x < 30; x++)
                {
                    tileMap[x][y].draw(window);
                }
            }

            clock.restart();
        }
    }
    exit(0);
}