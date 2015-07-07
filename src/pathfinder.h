#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <queue>
#include "node.h"

enum heuristicType { MANHATTAN, DIAGONAL, EUCLIDEAN };
enum pathfinderType { ASTAR, DIJKSTRA };

class Pathfinder
{
protected:
    heuristicType type;
public:
    Pathfinder();
    bool findPath(Node *, Node *);
    list<Node*> getPath(Node *);
    heuristicType getHeuristicType();
    void setHeuristicType(heuristicType);
    virtual float heuristic(Node *, Node *) = 0;
};

