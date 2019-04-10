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
struct node{
	T val;
	node * next;
};

template <typename T>
class Stack{
	public:
		LinkedList();
		~LinkedList();

		void insertVal(T val, int index);
		void deleteVal(int index);
		void insertFront(T val);
		void insertEnd(T val);
		
		void reverseLL();
		void get(int index);
		void printLL();
		
		bool isEmpty();

	private:
		singleNode * head;	
};
