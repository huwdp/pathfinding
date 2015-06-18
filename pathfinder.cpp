#include "pathfinder.h"
#include "comparef.h"

Pathfinder::Pathfinder()
{

}

bool Pathfinder::findPath(Node *start, Node *goal)
{
    priority_queue<Node*, vector<Node*>, CompareF> open;
    start->g = 0;
    start->f = 0;
    open.push(start);
    Node *prev;
    while (!open.empty())
    {
        Node *best = open.top();
        open.pop();
        best->closed = true;
        if (best == goal)
        {
            return true;
        }
        for (vector<Node*>::iterator it = best->nodes.begin() ; it != best->nodes.end(); ++it)
        {
            Node *current = (*it);
            float g = start->g + heuristic(start, current);
            if (!current->opened || g < current->g)
            {
                current->g = g;
                current->f = g + heuristic(current, goal);
                current->parent = best;
                if (!current->opened)
                {
                    current->opened = true;
                    open.push(current);
                }
            }
        }
        prev = best;
    }
    return false;
}

list<Node*> Pathfinder::getPath(Node *node)
{
    list<Node *> nodes;
    while (node != NULL)
    {
        nodes.push_front(node);
        node = node->parent;
    }
    return nodes;
}
