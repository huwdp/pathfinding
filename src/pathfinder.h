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
public:
    Pathfinder();
    ~Pathfinder();
    heuristicType type;
    bool findPath(Node *, Node *);
    list<Node*> getPath(Node *);
    virtual float heuristic(Node *, Node *) = 0;
};

