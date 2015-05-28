#include "node.h"

Node::Node(string name, float x, float y)
{
    this->name = name;
    this->x = x;
    this->y = y;
    g = f = numeric_limits<float>::infinity();
    closed = false;
    used = false;
}

void Node::AddNode(Node *node)
{
    nodes.push_back(node);
}
