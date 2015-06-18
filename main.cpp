#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

#include "node.h"
#include "comparef.h"

using namespace std;

float heuristic(Node *node, Node *next)
{
    float dx = (node->x - next->x);
    float dy = (node->y - next->y);
    return sqrt(dx * dx + dy * dy);
}

bool findPath(Node *start, Node *goal)
{
    priority_queue<Node*, vector<Node*>, CompareF> open;
    start->g = 0;
    start->f = 0;
    open.push(start);
    Node *prev;
    while (!open.empty())
    {
        Node *best = open.top();
        open.pop();
        best->closed = true;
        if (best == goal)
        {
            if (prev != NULL)
                prev->parent = best;
            return true;
        }
        for (vector<Node*>::iterator it = best->nodes.begin() ; it != best->nodes.end(); ++it)
        {
            Node *current = (*it);
            float g = start->g + heuristic(start, current);
            if (!current->opened || g < current->g)
            {
                current->g = g;
                current->f = g + heuristic(current, goal);
                best->parent = current;
                current->child = best;
                if (!current->opened)
                {
                    current->opened = true;
                    open.push(current);
                }
            }
        }
        prev = best;
    }
    return false;
}

void printPath(vector<Node*> nodes)
{
    for (vector<Node*>::iterator it = nodes.begin() ; it != nodes.end(); ++it)
    {
        cout << "Node" << (*it)->name << endl;
    }
}

vector<Node*> getPath(Node *node)
{
    vector<Node *> nodes;
    while (node != NULL)
    {
        nodes.push_back(node);
        node = node->parent;
    }
    return nodes;
}

int main()
{
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
    if (findPath(node1, node5))
        printPath(getPath(node1));
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}
