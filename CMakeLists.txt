cmake_minimum_required(VERSION 3.21)
project(Graph)

set(CMAKE_CXX_STANDARD 23)

add_executable(Graph main.cpp graph/Graph.h graph/AdjacentListGraph.cpp graph/AdjacentListGraph.h graph/AdjacentMatrixGraph.cpp graph/AdjacentMatrixGraph.h prority_queue/PriorityQueue.cpp prority_queue/PriorityQueue.h weighted_graph/WeightedGraph.h weighted_graph/AdjacentListWeightedGraph.cpp weighted_graph/AdjacentListWeightedGraph.h dsu/DisjointSetUnion.cpp dsu/DisjointSetUnion.h weighted_graph/Edge.h)
