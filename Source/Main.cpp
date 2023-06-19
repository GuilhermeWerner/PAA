#include "Graph.h"

int main()
{
    int nodes = 6;
    Graph *g1 = new Graph(nodes);

    g1->InsertD(0, 1);
    g1->InsertD(0, 2);
    g1->InsertD(0, 3);
    g1->InsertD(1, 2);
    g1->InsertD(1, 3);
    g1->InsertD(1, 5);
    g1->InsertD(2, 3);
    g1->InsertD(3, 5);
    g1->InsertD(4, 0);
    g1->InsertD(4, 2);

    cout << "-- TRANSITIVE CLOSURE --" << endl;
    g1->TransitiveClosure();

    // cout << "M1:" << endl;
    // g1->PrintIncidenceMatrix();
    // g1->PrintAdjacencyMatrix();
    // auto m1 = g1->GetIncidenceMatrix();

    // Graph *g2 = g1->ToTransitiveClosure();
    // cout << "M2:" << endl;
    // g2->PrintIncidenceMatrix();
    // g2->PrintAdjacencyMatrix();
    // auto m2 = g2->GetIncidenceMatrix();

    // auto m3 = Graph::MultiplyIncidenceMatrix(m1, m2);
    // Graph *g3 = new Graph(m3);
    // cout << "M3:" << endl;
    // g3->PrintIncidenceMatrix();
    // g3->PrintAdjacencyMatrix();

    return 0;
}
