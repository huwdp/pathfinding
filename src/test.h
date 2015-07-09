#pragma once
#include "pathfinder.h"
#include "testtype.h"
#include "astar.h"
#include "dijkstra.h"

class Test
{
private:
    vector<Node *> nodes;
    Node *start;
    Node *goal;
    vector<TestType> testTypes; // The test types, ASTAR, DIJKSTRA, etc.
    list<Node *> expected;      // Expected results
public:
    Test();
    ~Test();
    void addNode(Node *);
    void setStart(Node *);
    Node *getStart();
    void setGoal(Node *);
    Node *getGoal();
    void addExpected(Node *);
    bool isTrue();
    void addTestType(TestType);
};
