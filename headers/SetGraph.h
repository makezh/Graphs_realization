#ifndef GRAPHS_SETGRAPH_H
#define GRAPHS_SETGRAPH_H

#include "IGraph.h"
#include <unordered_set>

struct SetGraph: public IGraph {
public:
    SetGraph(int size);

    SetGraph(const IGraph &graph);

    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;
    void Print();

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;


private:
    std::vector<std::unordered_set<int>> adjacencySet;
};

#endif //GRAPHS_SETGRAPH_H
