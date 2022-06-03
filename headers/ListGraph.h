#ifndef GRAPHS_LISTGRAPH_H
#define GRAPHS_LISTGRAPH_H

#include "IGraph.h"

struct ListGraph: public IGraph
{
public:
    ListGraph(int size);

    ListGraph(const IGraph &graph);

    ~ListGraph() = default;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};



#endif //GRAPHS_LISTGRAPH_H
