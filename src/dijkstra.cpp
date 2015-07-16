#include "dijkstra.h"

Dijkstra::Dijkstra() : Pathfinder()
{
}

Dijkstra::~Dijkstra()
{

}

float Dijkstra::heuristic(INode *, INode *)
{
    return 0.0f;
}
