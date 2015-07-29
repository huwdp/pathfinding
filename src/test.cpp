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

#include "test.h"

namespace pathfinder
{
    Test::Test()
    {
        start = nullptr;
        goal = nullptr;
    }

    Test::~Test()
    {
        for (vector<INode*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
        {
            delete (*it);
        }
    }

    void Test::addNode(INode *node)
    {
        nodes.push_back(node);
    }

    void Test::setStart(INode *node)
    {
        start = node;
    }

    INode *Test::getStart()
    {
        return start;
    }

    void Test::setGoal(INode *node)
    {
        goal = node;
    }

    INode *Test::getGoal()
    {
        return goal;
    }

    void Test::addExpected(INode *node)
    {
        expected.push_back(node);
    }

    bool Test::isTrue()
    {
        if (start == nullptr || goal == nullptr)
        {
            return false;
        }
        // Foreach pathfinder
        //  Check if result is expected, if not then return false
        for (vector<TestType>::iterator it = testTypes.begin(); it != testTypes.end(); ++it)
        {
           if ((*it).getPathfinderType() == ASTAR)
           {
                AStar *astar = new AStar((*it).getHeuristicType());
                if (astar->findPath(start, goal))
                {
                    if (astar->getPath(goal) != expected)
                    {
                        return false;
                    }
                }
                delete astar;
           }
           else if ((*it).getPathfinderType() == DIJKSTRA)
           {
               Dijkstra *dijkstra = new Dijkstra();
               if (dijkstra->findPath(start, goal))
               {
                   if (dijkstra->getPath(goal) != expected)
                   {
                       return false;
                   }
               }
               delete dijkstra;
           }
           else
           {
               cout << "No pathfinder selected." << endl;
               return false;
           }
           for (vector<INode*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
           {
               (*it)->reset();
           }
        }
        return true;
    }

    void Test::addTestType(TestType testType)
    {
        testTypes.push_back(testType);
    }
}
