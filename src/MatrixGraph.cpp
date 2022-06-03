#include "MatrixGraph.h"
#include "cassert"

using namespace std;

MatrixGraph::MatrixGraph(int size) : adjacencyMatrix(size, vector<int>(size, 0)) {}

MatrixGraph::MatrixGraph(const IGraph &graph) : adjacencyMatrix(graph.VerticesCount(),
                                                                vector<int>(graph.VerticesCount(), 0)) {
    for(int i = 0; i < graph.VerticesCount(); i++) {
        vector<int> vertices = graph.GetNextVertices(i);
        for(auto j: vertices) {
            adjacencyMatrix[i][j] = 1;
        }
    }

}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencyMatrix.size());
    assert(0 <= to && to < adjacencyMatrix.size());
    adjacencyMatrix[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return (int) adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    vector<int> nextVertices;
    for(int i = 0; i < adjacencyMatrix.size(); i++) {
        if (adjacencyMatrix[vertex][i] == 1) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    vector<int> prevVertices;
    for(int i = 0; i < adjacencyMatrix.size(); i++) {
        if (adjacencyMatrix[i][vertex] == 1) {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}

void MatrixGraph::Print() {
    for(auto & i : adjacencyMatrix) {
        for (int j = 0; j < adjacencyMatrix.size(); j++) {
            cout << i[j] << ' ';
        }
        cout << endl;
    }
}
