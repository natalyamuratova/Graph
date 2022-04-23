#include <vector>
#include "Edge.h"

#pragma once

using std::vector;
using std::set;
using std::pair;

class WeightedGraph {
public:
    virtual void insert(int v, int w, int wt) = 0;
    virtual void remove(int v, int w) = 0;
    virtual void clear() = 0;
    virtual int vertex_count() = 0;
    virtual int edges_count() = 0;
    virtual set<pair<int, int>> adjacent_vertex(int v) = 0;
    virtual void print() = 0;
    virtual vector<Edge> get_edges() = 0;
};