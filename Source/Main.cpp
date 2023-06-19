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

    cout << "-- MATRIX --" << endl;
    g1->TransitiveReduction1();

    cout << "\n-- LOOPS --" << endl;
    g1->TransitiveReduction2();

    cout << "\n-- PERMUTATION --" << endl;
    g1->TransitiveReduction3();

    return 0;
}
