#include <vector>
#include <set>
#include "Graph.h"

#pragma once

using std::vector;
using std::set;

class AdjacentListGraph : public Graph {
    int v_count;
    int e_count;
    vector<set<int>> g;
    // map<int, set<int>> g;

public:
    AdjacentListGraph(int v_count);
    ~AdjacentListGraph();

    void insert(int v, int w) override;
    void remove(int v, int w) override;
    void clear() override;
    int vertex_count() override;
    int edges_count() override;
    vector<int> adjacent_vertex(int v) override;
};
