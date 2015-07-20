#pragma once
#include "pathfinder.h"
#include "testtype.h"
#include "astar.h"
#include "dijkstra.h"
#include "node.h"

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
    bool isTrue();
    void addTestType(TestType);
};
