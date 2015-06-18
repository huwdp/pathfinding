#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <queue>
#include "node.h"

enum heuristicType { NONE, MANHATTAN, DIAGONAL, EUCLIDEAN };

class Pathfinder
{
public:
    Pathfinder();
    heuristicType type;
    bool findPath(Node *, Node *);
    list<Node*> getPath(Node *);
    virtual float heuristic(Node *, Node *) = 0;
};

