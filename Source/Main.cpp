#include "Graph.h"

int main()
{
    cout << "-- GRAPH 1 --" << endl;
    int n1 = 6;
    Graph *g1 = new Graph(n1);

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

    cout << "-- GRAPH 2 --" << endl;
    int n2 = 7;
    Graph *g2 = new Graph(n2);

    g2->InsertD(0, 1);
    g2->InsertD(0, 4);
    g2->InsertD(1, 2);
    g2->InsertD(1, 3);
    g2->InsertD(1, 6);
    g2->InsertD(3, 2);
    g2->InsertD(4, 1);
    g2->InsertD(5, 1);

    cout << "-- MATRIX --" << endl;
    g2->TransitiveReduction1();

    cout << "\n-- LOOPS --" << endl;
    g2->TransitiveReduction2();

    cout << "\n-- PERMUTATION --" << endl;
    g2->TransitiveReduction3();

    return 0;
}
