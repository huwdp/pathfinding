#pragma once
#include "pathfinder.h"
#include "inode.h"
#include "math.h"


class AStar : public Pathfinder
{
private:
    int d, d2;
public:
    AStar(heuristicType);
    ~AStar();
    float getD();
    void setD(float);
    float getD2();
    void setD2(float);
    float heuristic(INode *, INode *);
    float manhattan(INode *, INode *);
    float diagonal(INode *, INode *);
    float euclidean(INode *, INode *);
};
