#include <vector>
#include <iostream>


template <class T>
struct vertice{


	vector<T> key;
}


template <class T>
class Graph{
	public:
		Graph(int size);
		friend ostream& operator <<(ostream& os, Graph& g){
			for(int i = 0; i < sizel i++){
				std::cout<<graph[i]<< " "<<std::endl;
			}
		}



	private:
		vector<T> graph;
		int size;
}
