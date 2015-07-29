/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Huw David Pritchard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "inode.h"

namespace pathfinder
{
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
}
