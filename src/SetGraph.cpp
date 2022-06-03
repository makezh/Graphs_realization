#include "SetGraph.h"
#include <cassert>

using namespace std;

SetGraph::SetGraph(int size) : adjacencySet(size) {}

SetGraph::SetGraph(const IGraph &graph) : adjacencySet(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (auto j: graph.GetNextVertices(i)) {
            adjacencySet[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencySet.size());
    assert(0 <= to && to < adjacencySet.size());
    adjacencySet[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return (int) adjacencySet.size();
}

vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencySet.size());
    vector<int> next_vert;
    for(auto i: adjacencySet[vertex])
        next_vert.push_back(i);
    std::sort(next_vert.begin(), next_vert.end());
    return next_vert;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencySet.size());
    std::vector<int> prev_vert;

    for (int from = 0; from < adjacencySet.size(); from++) {
        for (auto to: adjacencySet[from]) {
            if (to == vertex)
                prev_vert.push_back(from);
        }
    }
    std::sort(prev_vert.begin(), prev_vert.end());
    return prev_vert;
}


