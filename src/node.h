#pragma once
#include "inode.h"


class Node : public INode
{
private:
    string name;
public:
    Node(string, float, float);
    string getName();
    void setName(string);
};
