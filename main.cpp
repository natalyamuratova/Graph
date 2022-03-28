#include "Graph.h"
#include "AdjacentListGraph.h"
#include "AdjacentMatrixGraph.h"
#include <iostream>
#include <stack>
#include <queue>

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

void number_of_paper_sheets() {
    Graph* g = new AdjacentListGraph(10);
    g->insert(0, 1);
    g->insert(4, 5);
    g->insert(5, 6);
    g->insert(6, 7);
    g->insert(7, 8);

    int cur_vertex = 0;
    dfs(g, cur_vertex);
}

int main() {
    dfs_example();
//    number_of_paper_sheets();
    return 0;
}