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

#pragma once
#include "pathfinder.h"
#include "testtype.h"
#include "astar.h"
#include "dijkstra.h"
#include "node.h"

#include <list>

namespace pathfinder
{
    class Test
    {
    private:
        vector<INode *> nodes;
        INode *start;
        INode *goal;
        vector<TestType> testTypes; // The test types, ASTAR, DIJKSTRA, etc.
        list<INode *> expected;      // Expected results
    public:
        Test();
        ~Test();
        void addNode(INode *);
        void setStart(INode *);
        INode *getStart();
        void setGoal(INode *);
        INode *getGoal();
        void addExpected(INode *);
        list<INode*> getExpected();
        void setExpected(list<INode*> nodes);
        bool isTrue();
        void addTestType(TestType);
    };
}
