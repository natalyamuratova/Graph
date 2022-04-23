#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "graph/Graph.h"
#include "graph/AdjacentListGraph.h"
#include "graph/AdjacentMatrixGraph.h"
#include "prority_queue/PriorityQueue.h"
#include "weighted_graph/WeightedGraph.h"
#include "weighted_graph/AdjacentListWeightedGraph.h"
#include "dsu/DisjointSetUnion.h"

using namespace std;

// Recursive implementation of DFS for graph.
void dfs_recursive(int cur_vertex, vector<bool>& visited, Graph* g) {
    visited[cur_vertex] = true;
    cout << " " << cur_vertex;

    vector<int> adj = g->adjacent_vertex(cur_vertex);
    for (auto i : adj) {
        if (!visited[i]) {
            dfs_recursive(i, visited, g);
        }
    }
}

// Entry point of recursive implementation of DFS.
void dfs_recursive_init(Graph* g) {
    int cur_vertex = 0;

    int size = g->vertex_count();
    vector<bool> visited(size, false);

    dfs_recursive(cur_vertex, visited, g);
}

// Depth-First Search
void dfs(Graph* g, int cur_vertex) {
    int size = g->vertex_count();
    vector<bool> visited(size, false);

    stack<int> s;
    s.push(cur_vertex);
    visited[cur_vertex] = true;

    while (!s.empty()) {
        cur_vertex = s.top();
        s.pop();

        cout << " " << cur_vertex;

        vector<int> adj = g->adjacent_vertex(cur_vertex);
        for (auto i : adj) {
            if (!visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

// Breadth-First Search
void bfs(Graph* g) {
    int cur_vertex = 0;

    int size = g->vertex_count();
    vector<bool> visited(size, false);

    queue<int> q;
    q.push(cur_vertex);
    visited[cur_vertex] = true;

    while (!q.empty()) {
        cur_vertex = q.front();
        q.pop();

        cout << " " << cur_vertex;

        vector<int> adj = g->adjacent_vertex(cur_vertex);
        for (auto i : adj) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// Example of DFS and BFS algorithms for graph.
void dfs_example() {
    //Graph* g = new AdjacentMatrixGraph(8);
    Graph* g = new AdjacentListGraph(8);
    g->insert(0, 1);
    g->insert(0, 7);
    g->insert(0, 2);

    g->insert(1, 7);
    g->insert(7, 2);

    g->insert(7, 4);

    g->insert(5, 3);
    g->insert(4, 3);
    g->insert(4, 5);

    g->insert(0, 5);
    g->insert(6, 4);
    g->insert(0, 6);

    // dfs(g);
    // bfs(g);
    dfs_recursive_init(g);

    g->clear();
    delete g;
    g = nullptr;
}

// Task with paper list section start.
vector<pair<int, int>> adjacent_vertex_list(pair<int, int> vertex, vector<string> g) {
    vector<pair<int, int>> res;
    int i = vertex.first;
    int j = vertex.second;

    int rows_number = g.size();
    int columns_number = 0;
    if (g.size() > 0) {
        columns_number = g[0].size();
    }

    if (i < rows_number - 1 && g[i+1][j] == '#') {
        res.emplace_back(pair(i+1, j));
    }
    if (i > 1 && g[i-1][j] == '#') {
        res.emplace_back(pair(i-1, j));
    }
    if (j > 1 && g[i][j-1] == '#') {
        res.emplace_back(pair(i, j-1));
    }
    if (j < columns_number - 1 && g[i][j+1] == '#') {
        res.emplace_back(pair(i, j+1));
    }

    return res;
}

void dfs_for_list(pair<int, int>& vertex, vector<vector<bool>>& visited, vector<string> g) {
    visited[vertex.first][vertex.second] = true;

    vector<pair<int, int>> adj = adjacent_vertex_list(vertex, g);
    for (auto i : adj) {
        if (!visited[i.first][i.second]) {
            dfs_for_list(i, visited, g);
        }
    }
}

void number_of_paper_sheets() {
    int rows_number = 5;
    int columns_number = 10;

    vector<string> paper(rows_number);
    paper[0] = "##..#####.";
    paper[1] = ".#.#.#....";
    paper[2] = "###..##.#.";
    paper[3] = "..##.....#";
    paper[4] = ".###.#####";

    vector<vector<bool>> visited(rows_number, vector<bool>(columns_number, false));

    int n_comp = 0;

    for (int i = 0; i < rows_number; i++) {
        for (int j = 0; j < columns_number; j++) {
            if (paper[i][j] == '#' && !visited[i][j]) {
                pair<int, int> cur_vertex(i, j);
                dfs_for_list(cur_vertex, visited, paper);
                n_comp++;
            }
        }
    }

    cout << "Number of lists in paper = " << n_comp << endl;
}
// Section end.

// Prima section start
void priority_queue_example() {
    PriorityQueue queue;
    queue.push(12);
    queue.push(11);
    queue.push(13);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(70);
    queue.push(34);
    queue.push(90);
    queue.print_as_tree();

    queue.sort();
    queue.print_as_tree();
}

WeightedGraph* buildWeightedGraph() {
    WeightedGraph* g = new AdjacentListWeightedGraph(6);
    g->insert(0, 1, 6);
    g->insert(0, 2, 1);
    g->insert(0, 3, 5);

    g->insert(1, 2, 5);
    g->insert(1, 4, 3);

    g->insert(2, 3, 5);
    g->insert(2, 4, 6);
    g->insert(2, 5, 4);

    g->insert(3, 5, 2);

    g->insert(4, 5, 6);

    return g;
}

typedef pair<int, int> iPair;

struct ComparePairs {
    bool operator()(iPair const& p1, iPair const& p2) {
        return p1.second > p2.second;
    }
};

// The main function that constructs Minimum Spanning Tree (MST) using Prim's algorithm
void primMST(WeightedGraph* g) {
    int V = g->vertex_count();

    int mst_weight = 0;

    vector<bool> used(V, false);
    priority_queue<iPair, vector<iPair>, ComparePairs> q;

    int cur_vertex = 0;
    q.push({cur_vertex, 0});

    while (!q.empty()) {
        iPair c = q.top();
        q.pop();

        int v = c.first, dst = c.second;

        if (!used[v]) {
            used[v] = true;
            mst_weight += dst;

            set<iPair> adj = g->adjacent_vertex(v);
            for (auto e : adj) {
                int u = e.first, len_vu = e.second;
                if (!used[u]) {
                    q.push({u, len_vu});
                }
            }
        }
    }

    cout << "Minimum spanning tree weight: " << mst_weight << endl;
}

bool compareEdges(Edge& e1, Edge& e2){
    return e1.wt > e2.wt;
}

// The main function that constructs Minimum Spanning Tree (MST) using Kruskal's algorithm
void kruskalMST(WeightedGraph* g) {
    int mst_weight = 0;

    DisjointSetUnion comp(g->vertex_count());

    vector<Edge> edges = g->get_edges();
    std::sort(edges.begin(), edges.end(), compareEdges);

    for (auto edge: edges) {
        if (comp.merge(edge.v1, edge.v2)) {
            mst_weight += edge.wt;
        }
    }
    cout << "Minimum spanning tree weight: " << mst_weight << endl;
}

// Section end

int main() {
//    dfs_example();
//    number_of_paper_sheets();
//    priority_queue_example();

    WeightedGraph* g = buildWeightedGraph();
//    g->print();
    primMST(g);
    kruskalMST(g);

    return 0;
}