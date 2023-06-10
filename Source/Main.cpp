#include "Graph.h"

int main()
{
    int length = 9;
    Graph *g1 = new Graph(length);

    g1->Insert(0, 1);
    g1->Insert(0, 3);
    g1->Insert(0, 4);
    g1->Insert(1, 2);
    g1->Insert(1, 3);
    g1->Insert(1, 4);
    g1->Insert(2, 3);
    g1->Insert(2, 4);
    g1->Insert(2, 5);
    g1->Insert(3, 5);
    g1->Insert(4, 5);
    g1->Insert(5, 6);
    g1->Insert(6, 7);
    g1->Insert(6, 8);
    g1->Insert(7, 8);

    cout << "-- GRAFO --\n\n";
    g1->Print();

    return 0;
}
