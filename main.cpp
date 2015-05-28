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

float heuristic(struct Node *node, struct Node *next)
{
    float dx = (node->x - next->x);
    float dy = (node->y - next->y);
    return sqrt(dx * dx + dy * dy);
}

void findPath(Node *start, Node *goal)
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
            return;
        }
        for (vector<Node*>::iterator it = best->nodes.begin() ; it != best->nodes.end(); ++it)
        {
            Node *current = (*it);
            float g = start->g + heuristic(start, current);
            if (!current->used || g < current->g)
            {
                current->g = g;
                current->f = g + heuristic(current, goal);
                best->parent = current;
                current->child = best;
                if (!current->used)
                {
                    current->used = true;
                    open.push(current);
                }
            }
        }
        prev = best;
    }
}

void printPath(Node *node)
{
    while (node != NULL)
    {
        cout << "Node" << node->name << endl;
        node = node->parent;
    }
}

int main()
{
    Node *node1 = new Node("1", 1.0f, 1.0f);
    Node *node2 = new Node("2", 1.0f, 2.0f);
    Node *node3 = new Node("3", 8.0f, 8.0f);
    Node *node4 = new Node("4", 8.0f, 9.0f);
    Node *node5 = new Node("5", 10.0f, 10.0f);
    node1->AddNode(node2);
    node2->AddNode(node5);
    node1->AddNode(node3);
    node3->AddNode(node4);
    node4->AddNode(node5);
    findPath(node1, node5);
    printPath(node1);
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}
