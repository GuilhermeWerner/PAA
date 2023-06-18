#pragma once

#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <sstream>
#include <string.h>
#include <thread>

using namespace std;

const int MATRIX_LENGTH = 100;

class Graph
{
private:
    int nodes, edges;
    array<array<int, MATRIX_LENGTH>, MATRIX_LENGTH> matrix;

public:
    Graph(int nodes)
    {
        this->nodes = nodes;
        this->edges = 0;
        this->matrix.fill(array<int, MATRIX_LENGTH>{});
    }

    Graph(const Graph &other)
    {
        this->nodes = other.nodes;
        this->edges = other.edges;
        this->matrix = other.matrix;
    }

    Graph(const vector<vector<int>> &incidence)
    {
        this->nodes = incidence.size();
        this->edges = incidence[0].size();
        this->matrix.fill(array<int, MATRIX_LENGTH>{});

        for (int i = 0; i < this->nodes; i++)
        {
            for (int j = 0; j < this->edges; j++)
            {
                this->matrix[i][j] = incidence[i][j];
            }
        }
    }

    Graph(const vector<vector<int>> &adjacency, int nodes)
    {
        this->nodes = nodes;
        this->edges = 0;
        this->matrix.fill(array<int, MATRIX_LENGTH>{});

        for (int i = 0; i < this->nodes; i++)
        {
            for (int j = 0; j < this->nodes; j++)
            {
                if (adjacency[i][j] == 1)
                {
                    this->AddEdge(i, j);
                }
            }
        }
    }

    Graph *Clone() const
    {
        return new Graph(*this);
    }

public:
    void PrintIncidenceMatrix();

    void PrintAdjacencyMatrix();

    void AddEdge(int u, int v);

    vector<vector<int>> GetAdjacencyMatrix();

    vector<vector<int>> GetIncidenceMatrix();

    Graph *ToTransitiveClosure();

public:
    static vector<vector<int>> MultiplyIncidenceMatrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2)
    {
        int rows1 = matrix1.size();
        int cols1 = matrix1[0].size();
        int rows2 = matrix2.size();
        int cols2 = matrix2[0].size();

        // Cria uma matriz resultante com o tamanho apropriado
        vector<vector<int>> result(rows1, vector<int>(cols2, 0));

        // Realiza a multiplicação das matrizes
        for (auto i = 0; i < rows1; i++)
        {
            for (auto j = 0; j < cols2; j++)
            {
                result[i][j] = 0;

                for (auto k = 0; k < rows1; k++)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        return result;
    }

private:
    void _PrintAdjacencyMatrix(const vector<vector<int>> &adjacency)
    {
        int nodes = adjacency.size();

        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << adjacency[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }
};
