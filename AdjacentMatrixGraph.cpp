#include "AdjacentMatrixGraph.h"

AdjacentMatrixGraph::AdjacentMatrixGraph(int v_count)
{
    g.resize(v_count);
    for (int i = 0; i < v_count; i++) {
        g[i].resize(v_count, false);
    }
    this->v_count = v_count;
    this->e_count = 0;
}

AdjacentMatrixGraph::~AdjacentMatrixGraph()
{
    clear();
}

void AdjacentMatrixGraph::insert(int v, int w)
{
    if (v > v_count || w > v_count) {
        v_count = v > w ? v : w;
        g.resize(v_count);
        for (int i = 0; i < v_count; i++) {
            g.resize(v_count);
        }
    }

    g[v][w] = true;
    g[w][v] = true;
    e_count++;
}

void AdjacentMatrixGraph::remove(int v, int w)
{
    if (v > v_count || w > v_count) {
        return;
    }

    if (!g[v][w]) {
        return;
    }

    g[v][w] = false;
    g[w][v] = false;
    e_count--;
}

void AdjacentMatrixGraph::clear()
{
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    this->e_count = 0;
}

int AdjacentMatrixGraph::vertex_count()
{
    return v_count;
}

int AdjacentMatrixGraph::edges_count()
{
    return e_count;
}

vector<int> AdjacentMatrixGraph::adjacent_vertex(int v)
{
    if (v > v_count) {
        // throw new exception
        return vector<int>();
    }

    vector<int> adj;
    for (int i = 0; i < v_count; i++) {
        if (g[v][i]) {
            adj.push_back(i);
        }
    }

    return adj;
}
