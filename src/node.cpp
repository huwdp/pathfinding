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

float Node::getX()
{
    return x;
}

void Node::setX(float value)
{
    x = value;
}

float Node::getY()
{
    return y;
}

void Node::setY(float value)
{
    y = value;
}

float Node::getG()
{
    return g;
}

void Node::setG(float value)
{
    g = value;
}

float Node::getF()
{
    return f;
}

void Node::setF(float value)
{
    f = value;
}

Node *Node::getParent()
{
    return parent;
}

void Node::setParent(Node *node)
{
    parent = node;
}

float Node::getClosed()
{
    return closed;
}

void Node::setClosed(bool value)
{
    closed = value;
}

float Node::getOpened()
{
    return opened;
}

void Node::setOpened(bool value)
{
    opened = value;
}

vector<Node*> Node::getNodes()
{
    return nodes;
}

void Node::setNodes(vector<Node*> nodes)
{
    this->nodes = nodes;
}
