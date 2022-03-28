#include <vector>
#include "Graph.h"

#pragma once

using std::vector;

class AdjacentMatrixGraph : public Graph {
    int v_count;
    int e_count;
    vector<vector<bool>> g;

public:
    AdjacentMatrixGraph(int v_count);
    ~AdjacentMatrixGraph();

    void insert(int v, int w) override;
    void remove(int v, int w) override;
    void clear() override;
    int vertex_count() override;
    int edges_count() override;
    vector<int> adjacent_vertex(int v) override;
};