#pragma once
#include "node.h"

class CompareF {
public:
    bool operator()(Node *node1, Node* node2)
    {
        if (node1->getF() < node2->getF()) return true;
            return false;
    }
};
