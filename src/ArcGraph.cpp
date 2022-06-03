#include "ArcGraph.h"
#include "cassert"

using namespace std;

ArcGraph::ArcGraph(int size) : countVert(size){}

ArcGraph::ArcGraph(const IGraph &graph) : countVert(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); from++) {
        for (int to : graph.GetNextVertices(from)) {
            adjacencyPairs.emplace_back(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < countVert);
    assert(0 <= to && to < countVert);
    adjacencyPairs.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return countVert;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < countVert);
    vector<int> next_vert;
    for(auto vert: adjacencyPairs) {
        if(vert.first == vertex)
            next_vert.push_back(vert.second);
    }
    std::sort(next_vert.begin(), next_vert.end());
    return next_vert;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < countVert);
    vector<int> prev_vert;
    for(auto vert: adjacencyPairs) {
        if(vert.second == vertex)
            prev_vert.push_back(vert.first);
    }
    std::sort(prev_vert.begin(), prev_vert.end());
    return prev_vert;
}
