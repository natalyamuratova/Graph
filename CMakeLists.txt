cmake_minimum_required(VERSION 3.21)
project(Graph)

set(CMAKE_CXX_STANDARD 23)

add_executable(Graph main.cpp Graph.h AdjacentListGraph.cpp AdjacentListGraph.h AdjacentMatrixGraph.cpp AdjacentMatrixGraph.h PriorityQueue.cpp PriorityQueue.h WeightedGraph.h AdjacentListWeightedGraph.cpp AdjacentListWeightedGraph.h DisjointSetUnion.cpp DisjointSetUnion.h Edge.h)
