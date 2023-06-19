#include "Graph.h"
#include "Graph.h"

void Graph::Insert(int u, int v)
{
    InsertD(u, v);
    InsertD(v, u);
}

void Graph::InsertD(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::Remove(int u, int v)
{
    RemoveD(u, v);
    RemoveD(v, u);
}

void Graph::RemoveD(int u, int v)
{
    auto iv = find(adj[u].begin(), adj[u].end(), v);
    *iv = -1;
}

Graph *Graph::Clone()
{
    Graph *graph = new Graph(length);

    for (auto i = 0; i < length; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            graph->InsertD(i, *j);
        }
    }

    return graph;
}

void Graph::Print()
{
    for (auto i = 0; i < length; i++)
    {
        cout << "[" << i << "]: ";

        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            cout << *j << " ";
        }

        cout << endl;
    }
}

void Graph::TransitiveClosure()
{
    int m1[length][length];
    int m2[length][length];
    int m3[length][length];
    int gt[length][length];

    // Populate matrix

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            m1[i][j] = 0;
            m2[i][j] = 0;
            m3[i][j] = 0;
        }
    }

    for (auto i = 0; i < length; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            m1[i][*j] = 1;
            m2[i][*j] = 1;
        }
    }

    cout << "\nM1:" << endl;

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; ++j)
        {
            cout << m1[i][j] << " ";
        }

        cout << endl;
    }

    // Transitive closure

    for (auto k = 0; k < length; k++)
    {
        for (auto i = 0; i < length; i++)
        {
            for (auto j = 0; j < length; j++)
            {
                if (i == j)
                {
                    m2[i][j] = 1;
                }
                else
                {
                    m2[i][j] = m2[i][j] || (m2[i][k] && m2[k][j]);
                }
            }
        }
    }

    cout << "\nM2:" << endl;

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            cout << m2[i][j] << " ";
        }

        cout << endl;
    }

    // Multiply

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            m3[i][j] = 0;

            for (auto k = 0; k < length; k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    cout << "\nM3:" << endl;

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            cout << m3[i][j] << " ";
        }

        cout << endl;
    }

    // Remove

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            if (m1[i][j] == 1 && m3[i][j] == 1)
            {
                gt[i][j] = 1;
            }
            else
            {
                gt[i][j] = 0;
            }
        }
    }

    cout << "\nGt:" << endl;

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            cout << gt[i][j] << " ";
        }

        cout << endl;
    }
}
