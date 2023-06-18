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

bool Graph::HasEdge(int u, int v)
{
    auto iv = find(adj[u].begin(), adj[u].end(), v);
    return (iv != adj[u].end());
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

void Graph::DFS(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int>> &bridge)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;

    for (auto v : adj[u])
    {
        // vertice não visitado
        if (disc[v] == -1)
        {
            parent[v] = u;
            DFS(v, disc, low, parent, bridge);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
            {
                bridge.push_back({u, v});
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int Graph::DFSCount(int v, bool visited[])
{
    // marcar vertice como visitado
    visited[v] = true;
    int count = 1;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (*i != -1 && !visited[*i])
        {
            count += DFSCount(*i, visited);
        }
    }

    return count;
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

void Graph::TransitiveClosure2()
{
    // Populate matrix

    int reach[length][length];

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            reach[i][j] = 0;
        }
    }

    for (auto i = 0; i < length; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            reach[i][*j] = 1;
        }
    }

    // Transitive closure

    for (auto k = 0; k < length; k++)
    {
        for (auto i = 0; i < length; i++)
        {
            for (auto j = 0; j < length; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print matrix

    cout << "  ";

    for (int j = 0; j < length; j++)
    {
        cout << j << " ";
    }

    cout << "\n";

    for (int i = 0; i < length; i++)
    {
        cout << i << " ";

        for (int j = 0; j < length; j++)
        {
            if (i == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << reach[i][j] << " ";
            }
        }

        cout << "\n";
    }
}

void Graph::TransitiveReduce()
{
    for (auto a = 0; a < length; a++)
    {
        for (auto b = 0; b < length; b++)
        {
            if (HasEdge(a, b))
            {
                for (auto c = 0; c < length; c++)
                {
                    if (HasEdge(b, c))
                    {
                        // this->RemoveD();
                    }
                }
            }
        }
    }
}

void Graph::TransitiveClosure()
{
    int m1[length][length];
    int m2[length][length];
    int m3[length][length];

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
                m2[i][j] = m2[i][j] || (m2[i][k] && m2[k][j]);
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
            int temp = m1[i][j] - m3[i][j];
            m3[i][j] = temp > 0 ? temp : 0;
        }
    }

    cout << "\nGt:" << endl;

    for (auto i = 0; i < length; i++)
    {
        for (auto j = 0; j < length; j++)
        {
            cout << m3[i][j] << " ";
        }

        cout << endl;
    }
}
