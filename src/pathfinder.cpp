/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Huw David Pritchard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "pathfinder.h"
#include "comparef.h"
#include "math/compare.h"

namespace pathfinder
{
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
                float g = best->getG() + distance(best, current);
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
}
