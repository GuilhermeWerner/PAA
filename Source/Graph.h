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

    void AddEdge(int u, int v);

    vector<vector<int>> GetAdjacencyMatrix();

    vector<vector<int>> GetIncidenceMatrix();

    Graph *ToTransitiveClosure();

public:
    static void PrintAdjacencyMatrix(const vector<vector<int>> &adjacency)
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

    static vector<vector<int>> MultiplyIncidenceMatrix(const vector<vector<int>> &left, const vector<vector<int>> &right)
    {
        int rows1 = left.size();
        int cols1 = left[0].size();
        int rows2 = right.size();
        int cols2 = right[0].size();

        // Cria a matriz de resultado com o número de linhas de matrix1 e o número de colunas de matrix2
        vector<vector<int>> result(rows1 * rows2, vector<int>(cols1 * cols2, 0));

        // Realiza a multiplicação tensorial das matrizes de incidência
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols1; j++)
            {
                for (int k = 0; k < rows2; k++)
                {
                    for (int l = 0; l < cols2; l++)
                    {
                        result[i * rows2 + k][j * cols2 + l] = left[i][j] * right[k][l];
                    }
                }
            }
        }

        return result;
    }
};
