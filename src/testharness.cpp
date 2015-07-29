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

#include "testharness.h"
#include "inode.h"
#include "node.h"
namespace pathfinder
{
    TestHarness::TestHarness()
    {
        // Test 1
        Test *test1 = new Test();
        Node *node1 = new Node("1", 1.0f, 1.0f);
        Node *node2 = new Node("2", 1.0f, 2.0f);
        Node *node3 = new Node("3", 8.0f, 8.0f);
        Node *node4 = new Node("4", 8.0f, 9.0f);
        Node *node5 = new Node("5", 10.0f, 10.0f);
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
        test1->addTestType(TestType(DIJKSTRA));
        test1->addExpected(node1);
        test1->addExpected(node2);
        test1->addExpected(node5);
        this->tests.push_back(test1);




        Test *test2 = new Test();
        Node *node6 = new Node("6", 0.0f, 0.0f);
        Node *node7 = new Node("7", -2.0f, -2.0f);
        Node *node8 = new Node("8", 2.0f, -2.0f);
        Node *node9 = new Node("9", 0.0f, -3.0f);
        Node *node10 = new Node("10", -4.0f, -4.0f);
        Node *node11 = new Node("11", 4.0f, -4.0f);


        node6->addNode(node7);
        node6->addNode(node8);
        node7->addNode(node9);
        node7->addNode(node10);
        node8->addNode(node9);
        node8->addNode(node11);
        node10->addNode(node11);


        test2->setStart(node6);
        test2->setGoal(node11);


        test2->addExpected(node6);
        test2->addExpected(node8);
        test2->addExpected(node11);

        test2->addTestType(TestType(DIJKSTRA));
        test2->addTestType(TestType(ASTAR,EUCLIDEAN));
        this->tests.push_back(test2);



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
}






