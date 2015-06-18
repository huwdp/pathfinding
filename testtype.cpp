#include "testtype.h"

TestType::TestType(pathfinderType pathfinder, heuristicType heuristic)
{
    this->pathfinder = pathfinder;
    this->heuristic = heuristic;
}

pathfinderType TestType::getPathfinderType()
{
    return pathfinder;
}

heuristicType TestType::getHeuristicType()
{
    return heuristic;
}
