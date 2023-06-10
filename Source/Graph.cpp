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

    for (int i = 0; i < length; i++)
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

    for (int v : adj[u])
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
    for (int i = 0; i < length; i++)
    {
        cout << "[" << i << "]: ";

        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            cout << *j << " ";
        }

        cout << endl;
    }
}
