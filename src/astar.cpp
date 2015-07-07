#include "astar.h"

/*
 * http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html
 * Heuristics from Amit's Thoughts on Pathfinding
 */

AStar::AStar(heuristicType type) : Pathfinder()
{
    this->type = type;
    d = d2 = 1;
}

float AStar::getD()
{
    return d;
}

void AStar::setD(float value)
{
    d = value;
}

float AStar::getD2()
{
    return d2;
}

void AStar::setD2(float value)
{
    d2 = value;
}

float AStar::heuristic(Node *node, Node *next)
{
    switch (type)
    {
        case MANHATTAN:
            return manhattan(node, next);
            break;
        case DIAGONAL:
            return diagonal(node, next);
            break;
        case EUCLIDEAN:
            return euclidean(node, next);
            break;
    }
    return 1;
}

float AStar::manhattan(Node *node, Node *next)
{
    float dx = fabs(node->getX() - next->getX());
    float dy = fabs(node->getY() - next->getY());
    return d * (dx + dy);
}

float AStar::diagonal(Node *node, Node *next)
{
    float dx = fabs(node->getX() - next->getX());
    float dy = fabs(node->getY() - next->getY());
    return d * (dx + dy) + (d2 - 2 * d) * min(dx, dy);
}

float AStar::euclidean(Node *node, Node *next)
{
    float dx = fabs(node->getX() - next->getX());
    float dy = fabs(node->getY() - next->getY());
    return d * sqrt(dx * dx + dy * dy);
}
