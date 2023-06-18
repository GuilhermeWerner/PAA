#include "Graph.h"

int main()
{
    int nodes = 4;
    Graph *g1 = new Graph(nodes);

    g1->AddEdge(0, 1); // Edge 0
    g1->AddEdge(0, 2); // Edge 1
    g1->AddEdge(1, 2); // Edge 2
    g1->AddEdge(2, 0); // Edge 3
    g1->AddEdge(2, 3); // Edge 4

    cout << "M1:" << endl;
    g1->PrintIncidenceMatrix();
    auto m1 = g1->GetIncidenceMatrix();

    Graph *g2 = g1->ToTransitiveClosure();
    cout << "M2:" << endl;
    g2->PrintIncidenceMatrix();
    auto m2 = g2->GetIncidenceMatrix();

    auto m3 = Graph::MultiplyIncidenceMatrix(m1, m2);
    Graph *g3 = new Graph(m3);
    cout << "M3:" << endl;
    g3->PrintIncidenceMatrix();

    return 0;
}
