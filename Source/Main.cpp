#include "Graph.h"

int main()
{
    int length = 4;
    Graph *g1 = new Graph(length);

    g1->InsertD(0, 1);
    g1->InsertD(0, 2);
    g1->InsertD(1, 2);
    g1->InsertD(2, 0);
    g1->InsertD(2, 3);

    cout << "-- PERMUTATIONS --\n\n";
    g1->Permute();

    //cout << "-- TRANSITIVE CLOSURE --\n\n";
    //g1->TransitiveClosure();

    return 0;
}
