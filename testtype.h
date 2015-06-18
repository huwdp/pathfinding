#pragma once
#include "pathfinder.h"

class TestType
{
private:
    pathfinderType pathfinder;
    heuristicType heuristic;
public:
    TestType(pathfinderType pathfinder, heuristicType heuristic);
    pathfinderType getPathfinderType();
    heuristicType getHeuristicType();
};
