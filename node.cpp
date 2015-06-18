#include "node.h"

Node::Node(string name, float x, float y)
{
    this->name = name;
    this->x = x;
    this->y = y;
    parent = NULL;
    g = f = numeric_limits<float>::infinity();
    closed = opened =  false;
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
