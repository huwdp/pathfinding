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

#include "astar.h"
/*
 * http://theory.stanford.edu/~amitp/GameProgramming/Heuristics.html
 * Heuristics from Amit's Thoughts on Pathfinding
 */

namespace pathfinder
{
    AStar::AStar(heuristicType type) : Pathfinder()
    {
        this->type = type;
        d = d2 = 1;
    }

    AStar::~AStar()
    {

    }


    float AStar::getD()
    {
        return d;
    }

    void AStar::setD(float value)
    {
        d = value;
    }

    float AStar::getD2()
    {
        return d2;
    }

    void AStar::setD2(float value)
    {
        d2 = value;
    }

    float AStar::heuristic(INode *node, INode *next)
    {
        switch (type)
        {
            case MANHATTAN:
                return manhattan(node, next);
                break;
            case DIAGONAL:
                return diagonal(node, next);
                break;
            case EUCLIDEAN:
                return euclidean(node, next);
                break;
        }
        return 1;
    }

    float AStar::manhattan(INode *node, INode *next)
    {
        float dx = fabs(node->getX() - next->getX());
        float dy = fabs(node->getY() - next->getY());
        return d * (dx + dy);
    }

    float AStar::diagonal(INode *node, INode *next)
    {
        float dx = fabs(node->getX() - next->getX());
        float dy = fabs(node->getY() - next->getY());
        return d * (dx + dy) + (d2 - 2 * d) * min(dx, dy);
    }

    float AStar::euclidean(INode *node, INode *next)
    {
        float dx = fabs(node->getX() - next->getX());
        float dy = fabs(node->getY() - next->getY());
        return d * sqrt(dx * dx + dy * dy);
    }

    float AStar::distance(INode *node, INode *next)
    {
        float dx = fabs(node->getX() - next->getX());
        float dy = fabs(node->getY() - next->getY());
        return sqrt(dx * dx + dy * dy);
    }
}
