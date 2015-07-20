#include "inode.h"

INode::INode(float x, float y)
{
    this->x = x;
    this->y = y;
    reset();
}

void INode::reset()
{
    opened = closed = false;
    g = f = numeric_limits<float>::infinity();
    parent = nullptr;
}

void INode::addNode(INode *node)
{
    nodes.push_back(node);
}

float INode::getX()
{
    return x;
}

void INode::setX(float value)
{
    x = value;
}

float INode::getY()
{
    return y;
}

void INode::setY(float value)
{
    y = value;
}

float INode::getG()
{
    return g;
}

void INode::setG(float value)
{
    g = value;
}

float INode::getF()
{
    return f;
}

void INode::setF(float value)
{
    f = value;
}

INode *INode::getParent()
{
    return parent;
}

void INode::setParent(INode *node)
{
    parent = node;
}

float INode::getClosed()
{
    return closed;
}

void INode::setClosed(bool value)
{
    closed = value;
}

float INode::getOpened()
{
    return opened;
}

void INode::setOpened(bool value)
{
    opened = value;
}

vector<INode*> INode::getNodes()
{
    return nodes;
}

void INode::setNodes(vector<INode*> nodes)
{
    this->nodes = nodes;
}
