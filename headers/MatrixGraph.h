#ifndef GRAPHS_MATRIXGRAPH_H
#define GRAPHS_MATRIXGRAPH_H

#include "IGraph.h"

struct MatrixGraph: public IGraph {
public:
    MatrixGraph(int size);

    MatrixGraph(const IGraph &graph);

    ~MatrixGraph() override = default;

    void AddEdge(int from, int to) override;
    void Print();

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;


private:
    std::vector<std::vector<int>> adjacencyMatrix;
};

#endif //GRAPHS_MATRIXGRAPH_H
