#ifndef GRAPHS_IGRAPH_H
#define GRAPHS_IGRAPH_H

#include <iostream>
#include <vector>

struct IGraph {
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif //GRAPHS_IGRAPH_H
