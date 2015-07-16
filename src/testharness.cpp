#include "testharness.h"
#include "inode.h"

TestHarness::TestHarness()
{
    // Test 1
    Test *test1 = new Test();
    INode *Node1 = new INode("1", 1.0f, 1.0f);
    INode *Node2 = new INode("2", 1.0f, 2.0f);
    INode *Node3 = new INode("3", 8.0f, 8.0f);
    INode *Node4 = new INode("4", 8.0f, 9.0f);
    INode *Node5 = new INode("5", 10.0f, 10.0f);
    Node1->addNode(Node2);
    Node2->addNode(Node5);
    Node1->addNode(Node3);
    Node3->addNode(Node4);
    Node4->addNode(Node5);
    test1->addNode(Node1);
    test1->addNode(Node2);
    test1->addNode(Node3);
    test1->addNode(Node4);
    test1->addNode(Node5);
    test1->setStart(Node1);
    test1->setGoal(Node5);
    test1->addTestType(TestType(ASTAR,EUCLIDEAN));
    test1->addExpected(Node1);
    test1->addExpected(Node2);
    test1->addExpected(Node5);
    this->tests.push_back(test1);
}

TestHarness::~TestHarness()
{
    for (vector<Test*>::iterator it = tests.begin() ; it != tests.end(); ++it)
    {
        delete (*it);
    }
}

void TestHarness::checkTests()
{
    for (vector<Test*>::iterator it = tests.begin(); it != tests.end(); ++it)
    {
        if ((*it)->isTrue())
        {
            cout << "Test passed." << endl;
        }
        else
        {
            cout << "Test failed." << endl;
        }
    }
}






