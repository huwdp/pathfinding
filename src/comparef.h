#pragma once
#include "node.h"

class CompareF {
public:
    bool operator()(Node *node1, Node* node2)
    {
        if (node1->f < node2->f) return true;
            return false;
    }
};
