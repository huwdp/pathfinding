#include "test.h"

Test::Test()
{

}

Test::~Test()
{
    for (vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        delete (*it);
    }
}

void Test::addNode(Node *node)
{
    nodes.push_back(node);
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

void Test::addExpected(Node *node)
{
    expected.push_back(node);
}

bool Test::isTrue()
{
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
       for (vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
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
