#include "pathfinder.h"
#include "comparef.h"

Pathfinder::Pathfinder()
{

}

heuristicType Pathfinder::getHeuristicType()
{
    return type;
}

void Pathfinder::setHeuristicType(heuristicType type)
{
    this->type = type;
}

bool Pathfinder::findPath(Node *start, Node *goal)
{
    priority_queue<Node*, vector<Node*>, CompareF> open;
    start->setG(0);
    start->setF(0);
    open.push(start);
    while (!open.empty())
    {
        Node *best = open.top();
        open.pop();
        best->setClosed(true);
        if (best == goal)
        {
            return true;
        }
        for (vector<Node*>::iterator it = best->nodes.begin() ; it != best->nodes.end(); ++it)
        {
            Node *current = (*it);
            float g = start->getG() + heuristic(start, current);
            if (!current->getOpened() || g < current->getG())
            {
                current->setG(g);
                current->setF(g + heuristic(current, goal));
                current->setParent(best);
                if (!current->getOpened())
                {
                    current->setOpened(true);
                    open.push(current);
                }
            }
        }
    }
    return false;
}

list<Node*> Pathfinder::getPath(Node *node)
{
    list<Node *> nodes;
    while (node != nullptr)
    {
        nodes.push_front(node);
        node = node->getParent();
    }
    return nodes;
}
