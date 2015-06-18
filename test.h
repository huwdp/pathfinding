#pragma once
#include "pathfinder.h"
#include "testtype.h"

class Test
{
private:
    list<Node *> nodes;
    Node *start;
    Node *goal;
    vector<TestType> testTypes; // The test types, ASTAR, DIJKSTRA, etc.
    list<Node *> expected;      // Expected results
public:
    Test();
    ~Test();
    void addNode(Node *);
    void removeNode(Node *);
    void setStart(Node *);
    Node *getStart();
    void setGoal(Node *);
    Node *getGoal();
    bool isTrue();
};
