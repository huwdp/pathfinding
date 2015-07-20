#include "node.h"

Node::Node(string name, float x, float y) : INode(name, x, y)
{
    this->name = name;
}

string Node::getName()
{
    return name;
}

void Node::setName(string name)
{
    this->name = name;
}
