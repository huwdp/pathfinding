#pragma once
#include "pathfinder.h"
#include "node.h"
#include "math.h"


class AStar : public Pathfinder
{
public:
    AStar(heuristicType);
    ~AStar();
    int d, d2;
    float heuristic(Node *, Node *);
    float manhattan(Node *, Node *);
    float diagonal(Node *, Node *);
    float euclidean(Node *, Node *);
};
