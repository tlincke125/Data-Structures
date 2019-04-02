/****************************************************************/
/*                         Queue				*/
/****************************************************************/
/**
    CS-11 ASCI Standard 2, LinkedList.hpp
    Purpose: Used to store a dynamically allocated array using the Linked List data structure

    @author Theo Lincke
    @version 1.1 01/02/19 
*/

template <typename T>
struct singleNode{
	T val;
	node * next;
};

template <typename T>
class LLCircularQueue{
        public:
                Queue();
                ~Queue();

                void enqueue(T val);
                void dequeue(T val);
                bool isEmpty();
		void shift(int index);
                T peek();

        private:
                doubleNode<T> * head;
		doubleNode<T> * tail;
};

