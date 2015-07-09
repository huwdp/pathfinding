#pragma once

#include <string>
#include <vector>
#include <limits>
#include <cstddef>

using namespace std;

class Node
{
private:
    float x, y;
    float g, f;
    string name;
    Node *parent;
    bool closed;
    bool opened;
public:
    vector<Node*> nodes;
    Node(string, float, float);
    float getX();
    void setX(float);
    float getY();
    void setY(float);
    float getG();
    void setG(float);
    float getF();
    void setF(float);
    Node *getParent();
    void setParent(Node *);
    float getClosed();
    void setClosed(bool);
    float getOpened();
    void setOpened(bool);
    vector<Node*> getNodes();
    void setNodes(vector<Node*>);
    void addNode(Node *);
    void reset();
};
