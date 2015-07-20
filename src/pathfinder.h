#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <queue>
#include "inode.h"
#include <cstdint>

enum heuristicType { MANHATTAN, DIAGONAL, EUCLIDEAN };
enum pathfinderType { ASTAR, DIJKSTRA };

class Pathfinder
{
protected:
    heuristicType type;
public:
    Pathfinder();
    virtual ~Pathfinder();
    bool findPath(INode *, INode *);
    list<INode*> getPath(INode *);
    heuristicType getHeuristicType();
    void setHeuristicType(heuristicType);
    virtual float heuristic(INode *, INode *) = 0;
};

