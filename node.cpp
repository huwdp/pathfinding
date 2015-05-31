#include "node.h"

Node::Node(string name, float x, float y)
{
    this->name = name;
    this->x = x;
    this->y = y;
    g = f = numeric_limits<float>::infinity();
    closed = opened =  false;
}

void Node::reset()
{
    closed = false;
    opened = false;
}

void Node::addNode(Node *node)
{
    nodes.push_back(node);
}
