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
    bool opened;
    Node(string name, float x, float y);
    void addNode(Node *node);
    void reset();
};
