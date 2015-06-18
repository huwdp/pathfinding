#include "test.h"

Test::Test()
{

}

Test::~Test()
{
    // Remove nodes
}

void Test::addNode(Node *node)
{
    nodes.push_back(node);
}

void Test::removeNode(Node *node)
{
    nodes.remove(node);
}

void Test::setStart(Node *node)
{
    start = node;
}

Node *Test::getStart()
{
    return start;
}

void Test::setGoal(Node *node)
{
    goal = node;
}

Node *Test::getGoal()
{
    return goal;
}

bool Test::isTrue()
{
    // Foreach pathfinder
    //  Check if result is expected, if not then return false

    return true;
}
