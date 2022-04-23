#include <vector>
#include <set>
#include "WeightedGraph.h"

#pragma once

using std::vector;
using std::set;
using std::pair;

class AdjacentListWeightedGraph : public WeightedGraph {
    int v_count;
    int e_count;
    vector<set<pair<int, int>>> g;

public:
    AdjacentListWeightedGraph(int v_count);
    ~AdjacentListWeightedGraph();

    void insert(int v, int w, int wt) override;
    void remove(int v, int w) override;
    void clear() override;
    int vertex_count() override;
    int edges_count() override;
    set<pair<int, int>> adjacent_vertex(int v) override;
    void print() override;
    vector<Edge> get_edges();
};
