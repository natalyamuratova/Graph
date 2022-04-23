#pragma once

#include <vector>

class DisjointSetUnion {
private:
    std::vector<int> p;
    std::vector<int> rk;

public:
    explicit DisjointSetUnion(int size);

    int get_root(int v);
    size_t size();
    bool merge(int a, int b);
};
