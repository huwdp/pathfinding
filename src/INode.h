#pragma once

#include <string>
#include <vector>
#include <limits>
#include <cstddef>

using namespace std;

class INode
{
private:
    float x, y;
    float g, f;
    string name;
    INode *parent;
    bool closed;
    bool opened;
public:
    vector<INode*> nodes;
    INode(string, float, float);
    float getX();
    void setX(float);
    float getY();
    void setY(float);
    float getG();
    void setG(float);
    float getF();
    void setF(float);
    INode *getParent();
    void setParent(INode *);
    float getClosed();
    void setClosed(bool);
    float getOpened();
    void setOpened(bool);
    vector<INode*> getNodes();
    void setNodes(vector<INode*>);
    void addNode(INode *);
    void reset();
};
