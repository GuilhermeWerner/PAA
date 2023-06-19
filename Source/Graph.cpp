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

void Graph::TransitiveReduction1()
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

void Graph::TransitiveReduction2()
{
    int closure[this->length][this->length];

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = 0; j < this->length; j++)
        {
            closure[i][j] = 0;
        }
    }

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = this->adj[i].begin(); j != this->adj[i].end(); j++)
        {
            closure[i][*j] = 1;
        }
    }

    cout << "\nG1:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {

            cout << closure[i][j] << " ";
        }

        cout << endl;
    }

    for (auto k = 0; k < this->length; k++)
    {
        for (auto i = 0; i < this->length; i++)
        {
            for (auto j = 0; j < this->length; j++)
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

    cout << "\nTC:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (i == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << closure[i][j] << " ";
            }
        }

        cout << endl;
    }

    int reduction[this->length][this->length];

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = 0; j < this->length; j++)
        {
            reduction[i][j] = 0;
        }
    }

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            reduction[i][*j] = 1;
        }
    }

    for (auto j = 0; j < this->length; j++)
    {
        for (auto i = 0; i < this->length; i++)
        {
            if (reduction[i][j] == 1)
            {
                for (auto k = 0; k < this->length; k++)
                {
                    if (reduction[j][k] == 1)
                    {
                        reduction[i][k] = 0;
                    }
                }
            }
        }
    }

    cout << "\nG2:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {

            cout << reduction[i][j] << " ";
        }

        cout << endl;
    }

    for (auto k = 0; k < this->length; k++)
    {
        for (auto i = 0; i < this->length; i++)
        {
            for (auto j = 0; j < this->length; j++)
            {
                if (i == j)
                {
                    reduction[i][j] = 1;
                }
                else
                {
                    reduction[i][j] = reduction[i][j] || (reduction[i][k] && reduction[k][j]);
                }
            }
        }
    }

    cout << "\nTC:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (i == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << reduction[i][j] << " ";
            }
        }

        cout << endl;
    }
}

void Graph::TransitiveReduction3()
{
    int closure[this->length][this->length];

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = 0; j < this->length; j++)
        {
            closure[i][j] = 0;
        }
    }

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = this->adj[i].begin(); j != this->adj[i].end(); j++)
        {
            closure[i][*j] = 1;
        }
    }

    cout << "\nG1:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {

            cout << closure[i][j] << " ";
        }

        cout << endl;
    }

    for (auto k = 0; k < this->length; k++)
    {
        for (auto i = 0; i < this->length; i++)
        {
            for (auto j = 0; j < this->length; j++)
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

    cout << "\nTC:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (i == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << closure[i][j] << " ";
            }
        }

        cout << endl;
    }

    int reduction[this->length][this->length];

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = 0; j < this->length; j++)
        {
            reduction[i][j] = 0;
        }
    }

    for (auto i = 0; i < this->length; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            reduction[i][*j] = 1;
        }
    }

    for (int v = 0; v < this->length; ++v)
    {
        std::vector<std::vector<int>> paths;

        // Encontra todos os paths possíveis de v para outros vértices
        for (int j = 2; j <= this->length; ++j)
        {
            std::vector<int> path(j);

            for (int i = 0; i < j; ++i)
            {
                path[i] = i;
            }

            do
            {
                if (path[0] == v)
                {
                    paths.push_back(path);
                }
            } while (std::next_permutation(path.begin(), path.end()));
        }

        // Verifica se os paths são transitivos
        for (const auto &path : paths)
        {
            for (int i = 0; i < path.size() - 2; ++i)
            {
                if (reduction[path[i]][path[i + 1]] == 1 && reduction[path[i + 1]][path[i + 2]] == 1)
                {
                    reduction[path[i]][path[i + 2]] = 0;
                }
            }
        }
    }

    cout << "\nG2:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {

            cout << reduction[i][j] << " ";
        }

        cout << endl;
    }

    for (auto k = 0; k < this->length; k++)
    {
        for (auto i = 0; i < this->length; i++)
        {
            for (auto j = 0; j < this->length; j++)
            {
                if (i == j)
                {
                    reduction[i][j] = 1;
                }
                else
                {
                    reduction[i][j] = reduction[i][j] || (reduction[i][k] && reduction[k][j]);
                }
            }
        }
    }

    cout << "\nTC:" << endl;

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (i == j)
            {
                cout << "1 ";
            }
            else
            {
                cout << reduction[i][j] << " ";
            }
        }

        cout << endl;
    }
}
