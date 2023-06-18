#include "Graph.h"

int main()
{
    int nodes = 6;
    Graph *g1 = new Graph(nodes);

    g1->AddEdge(0, 0);
    g1->AddEdge(0, 1);
    g1->AddEdge(0, 2);
    g1->AddEdge(0, 3);
    g1->AddEdge(1, 2);
    g1->AddEdge(1, 3);
    g1->AddEdge(1, 5);
    g1->AddEdge(2, 3);
    g1->AddEdge(3, 5);
    g1->AddEdge(4, 0);
    g1->AddEdge(4, 2);

    cout << "M1:" << endl;
    g1->PrintIncidenceMatrix();
    g1->PrintAdjacencyMatrix();
    auto m1 = g1->GetIncidenceMatrix();

    Graph *g2 = g1->ToTransitiveClosure();
    cout << "M2:" << endl;
    g2->PrintIncidenceMatrix();
    g2->PrintAdjacencyMatrix();
    auto m2 = g2->GetIncidenceMatrix();

    auto m3 = Graph::MultiplyIncidenceMatrix(m1, m2);
    Graph *g3 = new Graph(m3);
    cout << "M3:" << endl;
    g3->PrintIncidenceMatrix();
    g3->PrintAdjacencyMatrix();

    return 0;
}
