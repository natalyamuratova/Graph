#include <string>
#include "AdjacentListGraph.h"

using std::string;

AdjacentListGraph::AdjacentListGraph(int v_count)
{
    g.resize(v_count);
    this->v_count = v_count;
    this->e_count = 0;
}

AdjacentListGraph::~AdjacentListGraph()
{
    clear();
}

void AdjacentListGraph::insert(int v, int w)
{
    if (v > v_count || w > v_count) {
        v_count = v > w ? v : w;
        g.resize(v_count);
    }

    g[v].insert(w);
    g[w].insert(v);
    e_count++;
}

void AdjacentListGraph::remove(int v, int w)
{
    if (v > v_count || w > v_count) {
        return;
    }

    if (g[v].find(w) != g[v].end()) {
        g[v].erase(w);
        g[w].erase(v);
        e_count--;
    }
}

void AdjacentListGraph::clear()
{
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    this->e_count = 0;
}

int AdjacentListGraph::vertex_count()
{
    return v_count;
}

int AdjacentListGraph::edges_count()
{
    return e_count;
}

vector<int> AdjacentListGraph::adjacent_vertex(int v)
{
    if (v > v_count) {
        throw string("vertex not found");
    }

    return vector<int>(g[v].begin(), g[v].end());
}