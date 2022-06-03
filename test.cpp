#include <iostream>
#include <functional>
#include <queue>
#include <stack>
#include "IGraph.h"
#include "ListGraph.h"
#include "SetGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"

////////// BFS //////////
void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph &graph, const std::function<void(int)> &func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            BFS(graph, i, visited, func);
    }
}
////////// End BFS //////////

////////// DFS //////////
void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func)
{
    std::stack<int> st;
    visited[vertex] = true;
    st.push(vertex);

    while (!st.empty())
    {
        int currentVertex = st.top();
        st.pop();

        func(currentVertex);

        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                st.push(nextVertex);
                visited[nextVertex] = true;
            }
        }
    }
}

void mainDFS(const IGraph &graph, const std::function<void(int)> &func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            DFS(graph, i, visited, func);
    }
}
////////// End DFS //////////

int main() {
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    MatrixGraph matrixGraph(listGraph);
    SetGraph setGraph(matrixGraph);
    ArcGraph arcGraph(setGraph);

    std::cout << "Testing graph realization:\n";

    std::cout << "\nTEST [Compare sizes]: ";
    if (listGraph.VerticesCount() == matrixGraph.VerticesCount() && listGraph.VerticesCount() == setGraph.VerticesCount() && listGraph.VerticesCount() == arcGraph.VerticesCount()) {
        std::cout << "OK!\n";
    } else {
        std::cout << "FAIL!\n";
        return 1;
    }

    std::cout << "TEST [Compare prevVertices]: ";
    for (int i = 0; i < listGraph.VerticesCount(); ++i) {
        if (listGraph.GetPrevVertices(i) != matrixGraph.GetPrevVertices(i) ||
            listGraph.GetPrevVertices(i) != setGraph.GetPrevVertices(i) ||
            listGraph.GetPrevVertices(i) != arcGraph.GetPrevVertices(i)) {
            std::cout << "FAIL!\n";
            return 1;
        }
    }
    std::cout << "OK!\n";

    std::cout << "TEST [Compare nextVertices]: ";
    for (int i = 0; i < listGraph.VerticesCount(); ++i) {
        if (listGraph.GetNextVertices(i) != matrixGraph.GetNextVertices(i) ||
            listGraph.GetNextVertices(i) != setGraph.GetNextVertices(i) ||
            listGraph.GetNextVertices(i) != arcGraph.GetNextVertices(i)) {
            std::cout << "FAIL!\n";
            return 1;
        }
    }
    std::cout << "OK!\n";

    std::cout << "\nBFS for listGraph: ";
    mainBFS(listGraph, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\nBFS for matrixGraph: ";
    mainBFS(matrixGraph, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\nBFS for setGraph: ";
    mainBFS(setGraph, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\nBFS for arcGraph: ";
    mainBFS(arcGraph, std::function<void(int)>([](int v){std::cout << v << ", ";}));

    std::cout << "\n";

}
