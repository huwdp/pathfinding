#include <stdio.h>
#include <stdlib.h>
#include "astar.h"
#include "dijkstra.h"
#include "node.h"
#include "comparef.h"

using namespace std;

void printPath(list<Node*> nodes)
{
    for (list<Node*>::iterator it = nodes.begin() ; it != nodes.end(); ++it)
    {
        cout << "Node" << (*it)->name << endl;
    }
}

int main()
{
    Node *node1 = new Node("1", 1.0f, 1.0f);
    Node *node2 = new Node("2", 1.0f, 2.0f);
    Node *node3 = new Node("3", 8.0f, 8.0f);
    Node *node4 = new Node("4", 8.0f, 9.0f);
    Node *node5 = new Node("5", 10.0f, 10.0f);
    node1->addNode(node2);
    node2->addNode(node5);
    node1->addNode(node3);
    node3->addNode(node4);
    node4->addNode(node5);

    AStar *astar = new AStar(EUCLIDEAN);
    if (astar->findPath(node1, node5))
       printPath(astar->getPath(node5));

    node1->reset();
    node2->reset();
    node3->reset();
    node4->reset();
    node5->reset();

    cout << endl;

    Dijkstra *dijkstra = new Dijkstra();
    if (dijkstra->findPath(node1, node5))
       printPath(dijkstra->getPath(node5));

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete dijkstra;
    delete astar;
    return 0;
}
