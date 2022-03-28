#include <vector>

#pragma once

using std::vector;

class Graph {
public:
    virtual void insert(int v, int w) = 0;
    virtual void remove(int v, int w) = 0;
    virtual void clear() = 0;
    virtual int vertex_count() = 0;
    virtual int edges_count() = 0;
    virtual vector<int> adjacent_vertex(int v) = 0;
};