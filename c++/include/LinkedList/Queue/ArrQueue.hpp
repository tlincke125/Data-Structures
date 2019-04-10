/****************************************************************/
/*                         Queue				*/
/****************************************************************/
/**
    CS-11 ASCI Standard 2, LinkedList.hpp
    Purpose: Used to store a dynamically allocated array using the Linked List data structure

    @author Theo Lincke
    @version 1.1 01/02/19 
*/

const int SIZE;

template <typename T>
class ArrQueue{
	public:
		ArrQueue();
		bool isEmpty();
		bool isFull();
		void enqueue(T val);
		void dequeue(T val);
		int queueSize();
		int getQueueFront();
		int getQueueEnd();
		T getQueue();
		T peek();

	private:
		int queueFront;
		int queueEnd;
		T queue[SIZE];
};
