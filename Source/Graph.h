#pragma once

#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <sstream>
#include <string.h>
#include <thread>

using namespace std;

class Graph
{
private:
    int length;
    list<int> *adj;

public:
    Graph(int length)
    {
        this->length = length;
        this->adj = new list<int>[length];
    }

    ~Graph()
    {
        delete[] adj;
    }

public:
    void Print();
    void Insert(int u, int v);
    void InsertD(int u, int v);
    void Remove(int u, int v);
    void RemoveD(int u, int v);
    void TransitiveClosure();
    Graph *Clone();
};
