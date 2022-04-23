#include <string>
#include <iostream>
#include "AdjacentListWeightedGraph.h"

using std::string;
using std::cout;
using std::make_pair;

AdjacentListWeightedGraph::AdjacentListWeightedGraph(int v_count)
{
    g.resize(v_count);
    this->v_count = v_count;
    this->e_count = 0;
}

AdjacentListWeightedGraph::~AdjacentListWeightedGraph()
{
    clear();
}

void AdjacentListWeightedGraph::insert(int v, int w, int wt)
{
    if (v > v_count || w > v_count) {
        v_count = v > w ? v : w;
        g.resize(v_count);
    }

    g[v].insert(make_pair(w, wt));
    g[w].insert(make_pair(v, wt));
    e_count++;
}

void AdjacentListWeightedGraph::remove(int v, int w)
{
    if (v > v_count || w > v_count) {
        return;
    }

    auto it_w = std::find_if(g[v].begin(), g[v].end(), [w](const pair<int,int>& p ){ return p.first == w; });
    auto it_v = std::find_if(g[w].begin(), g[w].end(), [v](const pair<int,int>& p ){ return p.first == v; });
    if (it_w != g[v].end() && it_v != g[w].end()) {
        g[v].erase(*it_w);
        g[w].erase(*it_v);
        e_count--;
    }
}

void AdjacentListWeightedGraph::clear()
{
    for (int i = 0; i < v_count; i++) {
        g[i].clear();
    }
    g.clear();
    this->e_count = 0;
}

int AdjacentListWeightedGraph::vertex_count()
{
    return v_count;
}

int AdjacentListWeightedGraph::edges_count()
{
    return e_count;
}

set<pair<int, int>> AdjacentListWeightedGraph::adjacent_vertex(int v)
{
    if (v > v_count) {
        throw string("vertex not found");
    }

    return g[v];
}

void AdjacentListWeightedGraph::print() {
    int v, dst ;
    for (int i = 0; i < v_count; i++) {
        cout << "Node " << i << " makes an edge with \n";
        for (const auto & it : g[i]) {
            v = it.first;
            dst = it.second;
            cout << "\tNode " << v << " with edge weight = " << dst << "\n";
        }
        cout << "\n";
    }
}

vector<Edge> AdjacentListWeightedGraph::get_edges() {
    vector<Edge> res;
    size_t n = g.size();
    for (int i = 0; i < n; i++) {
        auto adj_list = g[i];
        for (auto el: adj_list) {
            int v = el.first, dst = el.second;
            Edge ed(i, v, dst);
            auto ed_it = std::find_if(
                    res.begin(),
                    res.end(),
                    [ed](Edge h) { return (ed.v1 == h.v1 && ed.v2 == h.v2 || ed.v2 == h.v1 && ed.v1 == h.v2) && ed.wt == h.wt; }
                    );
            if (ed_it != res.end()) {
                res.push_back(ed);
            }
        }
    }
    return res;
}
