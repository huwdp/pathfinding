#pragma once

#include <string>
#include <vector>
#include <limits>

using namespace std;

class Node
{
public:
    float x, y;
    float g, f;
    string name;
    Node *parent;
    Node *child;
    vector<Node*> nodes;
    bool closed;
    bool used;
    Node(string name, float x, float y);
    void AddNode(Node *node);
};
