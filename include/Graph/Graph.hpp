#include <vector>
#include <iostream>

using std::vector
template <class T>
struct adjVertex{
	vertex *v;
}

template <class T>
struct vertex{
    T val;
    bool visited;
    std::vector<adjVertex> adj;
}

template <class T>
class Graph{
    public:
        Graph();
        ~Graph();
        void addEdge(T val1, T val2);
        void addVertex(T val);
        void displayEdges();
        void breadthFirstTraverse(T sourceVertex);

    private:
        vector<vertex> vertices;
}
