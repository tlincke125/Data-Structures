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
class Heap{
	public:
		Heap(int queueSize, bool Min);
        Heap(int size, int queueSize, T * arr, bool Min);
//        ~Heap();
        
		int parent(int index);
		int leftChild(int index);
		int rightChild(int index);

		T getMinMax();
		void heapify(int index);
		T extractMinMax();
		void insertElement(T val);
		void print();
		void deleteKey(T val);
	private:
        bool min;
		T * heapArr;
		int capacity;
		int currentSize;
};
#include "Heap_impl.tcc"
