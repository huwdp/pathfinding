#pragma once
#include "pathfinder.h"

class Dijkstra : public Pathfinder
{
public:
    Dijkstra();
    ~Dijkstra();
    float heuristic(INode *, INode *);
};
