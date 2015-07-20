#include "testharness.h"
#include "inode.h"
#include "node.h"

TestHarness::TestHarness()
{
    // Test 1
    Test *test1 = new Test();
    INode *node1 = new Node("1", 1.0f, 1.0f);
    INode *node2 = new Node("2", 1.0f, 2.0f);
    INode *node3 = new Node("3", 8.0f, 8.0f);
    INode *node4 = new Node("4", 8.0f, 9.0f);
    INode *node5 = new Node("5", 10.0f, 10.0f);
    node1->addNode(node2);
    node2->addNode(node5);
    node1->addNode(node3);
    node3->addNode(node4);
    node4->addNode(node5);
    test1->addNode(node1);
    test1->addNode(node2);
    test1->addNode(node3);
    test1->addNode(node4);
    test1->addNode(node5);
    test1->setStart(node1);
    test1->setGoal(node5);
    test1->addTestType(TestType(ASTAR,EUCLIDEAN));
    test1->addExpected(node1);
    test1->addExpected(node2);
    test1->addExpected(node5);
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






