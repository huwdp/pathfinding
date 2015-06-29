#include "dijkstra.h"

Dijkstra::Dijkstra() : Pathfinder()
{
}

Dijkstra::~Dijkstra()
{

}

float Dijkstra::heuristic(Node *, Node *)
{
    return 0.0f;
}
