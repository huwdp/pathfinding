#include "pathfinder.h"
#include "comparef.h"
#include "math/compare.h"

Pathfinder::Pathfinder()
{

}

Pathfinder::~Pathfinder()
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

bool Pathfinder::findPath(INode *start, INode *goal)
{
    priority_queue<INode*, vector<INode*>, CompareF> open;
    start->setG(0);
    start->setF(0);
    open.push(start);
    while (!open.empty())
    {
        INode *best = open.top();
        open.pop();
        best->setClosed(true);
        if (best == goal)
        {
            return true;
        }
        for (vector<INode*>::iterator it = best->nodes.begin() ; it != best->nodes.end(); ++it)
        {
            INode *current = (*it);
            float g = start->getG() + heuristic(start, current);
            if (!current->getOpened() || Compare::isUnder(g, current->getG()))
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

list<INode*> Pathfinder::getPath(INode *node)
{
    list<INode*> nodes;
    while (node != nullptr)
    {
        nodes.push_front(node);
        node = node->getParent();
    }
    return nodes;
}
