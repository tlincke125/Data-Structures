/****************************************************************/
/*                       Linked List				*/
/****************************************************************/
/**
    CS-11 ASCI Standard 2, LinkedList.hpp
    Purpose: Used to store a dynamically allocated array using the Linked List data structure

    @author Theo Lincke
    @version 1.1 01/02/19 
*/


template <typename T>
class MinHeap{
	public:
		MinHeap(int queueSize);
		int parent(int index);
		int leftChild(int index);
		int rightChild(int index);

		T getMin();
		void heapify(int index);
		T extractMin();
		void insertElement(T val);
		void print();
		void deleteKey(T val);
	private:
		T * heapArr;
		int capacity;
		int currentSize;
};
#include "Heap_impl.tcc"
