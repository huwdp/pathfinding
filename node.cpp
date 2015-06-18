#include "node.h"

Node::Node(string name, float x, float y)
{
    this->name = name;
    this->x = x;
    this->y = y;
    reset();
}

void Node::reset()
{
    opened = closed = false;
    g = f = numeric_limits<float>::infinity();
    parent = NULL;
}

void Node::addNode(Node *node)
{
    nodes.push_back(node);
}
