#pragma once
#include "pathfinder.h"
#include "node.h"
#include "math.h"


class AStar : public Pathfinder
{
private:
    int d, d2;
public:
    AStar(heuristicType);
    float getD();
    void setD(float);
    float getD2();
    void setD2(float);
    float heuristic(Node *, Node *);
    float manhattan(Node *, Node *);
    float diagonal(Node *, Node *);
    float euclidean(Node *, Node *);
};
