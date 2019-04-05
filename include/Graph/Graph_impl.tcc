#include <iostream>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

template <class T>
void Graph<T>::addEdge(T val1, T val2)
{
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].val = val1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[i].val == val2 && i != j){
                    adjVertex av;
                    av.v = vertices + j;
                    vertices[i].adj.push_back(av);
                    adjVertex av2;
                    av2.v = verticies + i;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

template <class T>
void Graph<T>::addVertex(T val)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].val == val)
        {
            found == true;
            cout<<vertices[i].val << "already exists" << endl;
        }
    }
    if(!found){
        vertex v;
        v.val = n;
        vertices.push_back(v);    
    }
}

template <class T>
void Graph<T>::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
    {
    }
}
