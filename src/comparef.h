#pragma once
#include "inode.h"

class CompareF {
public:
    bool operator()(INode *node1, INode* node2)
    {
        if (node1->getF() < node2->getF()) return true;
            return false;
    }
};
