#ifndef GRAPHS_ARCGRAPH_H
#define GRAPHS_ARCGRAPH_H

#include "IGraph.h"

struct ArcGraph: public IGraph {
public:
    ArcGraph(int size);

    ArcGraph(const IGraph &graph);

    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;


private:
    std::vector<std::pair<int, int>> adjacencyPairs;
    int countVert;
};

#endif //GRAPHS_ARCGRAPH_H
