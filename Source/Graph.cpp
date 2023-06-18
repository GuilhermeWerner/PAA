#include "Graph.h"

void Graph::PrintIncidenceMatrix()
{
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int val = this->matrix[i][j];

            if (val >= 0)
            {
                cout << " " << val << " ";
            }
            else
            {
                cout << val << " ";
            }
        }

        cout << endl;
    }

    cout << endl;
}

void Graph::PrintAdjacencyMatrix()
{
    Graph::_PrintAdjacencyMatrix(this->GetAdjacencyMatrix());
}

void Graph::AddEdge(int u, int v)
{
    this->matrix[u][this->edges] = 1;
    this->matrix[v][this->edges] = -1;
    this->edges++;
}

vector<vector<int>> Graph::GetAdjacencyMatrix()
{
    vector<vector<int>> adjacency(this->nodes, vector<int>(this->nodes, 0));

    // Converte uma matriz de incidência para de adjacência.
    for (int j = 0; j < this->edges; j++)
    {
        int u = -1, v = -1;

        for (int i = 0; i < this->nodes; i++)
        {
            if (this->matrix[i][j] == 1)
            {
                if (u == -1)
                {
                    u = i;
                }
            }
            else if (this->matrix[i][j] == -1)
            {
                if (v == -1)
                {
                    v = i;
                }
            }
        }

        if (u != -1 && v != -1)
        {
            adjacency[u][v] = 1;
        }
    }

    return adjacency;
}

vector<vector<int>> Graph::GetIncidenceMatrix()
{
    vector<vector<int>> incidence(this->nodes);

    for (int i = 0; i < this->nodes; i++)
    {
        for (int j = 0; j < this->edges; j++)
        {
            incidence[i].push_back(this->matrix[i][j]);
        }
    }

    return incidence;
}

Graph *Graph::ToTransitiveClosure()
{
    auto closure = this->GetAdjacencyMatrix();

    // Calcula o fecho transitivo do grafo.
    for (auto k = 0; k < this->nodes; k++)
    {
        for (auto i = 0; i < this->nodes; i++)
        {
            for (auto j = 0; j < this->nodes; j++)
            {
                if (i == j)
                {
                    closure[i][j] = 1;
                }
                else
                {
                    closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
                }
            }
        }
    }

    cout << "TC:" << endl;
    Graph::_PrintAdjacencyMatrix(closure);

    return new Graph(closure, closure.size());
}

/*
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
            if (m1[i][j] >= 1 && m3[i][j] >= 1)
            {
                m3[i][j] = 0;
            }
            else
            {
                m3[i][j] = m1[i][j];
            }
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
*/
