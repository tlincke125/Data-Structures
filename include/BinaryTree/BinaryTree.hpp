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
struct Node{
	T val;

	Node * left;
	Node * right;
};

template <typename T>
class BinaryTree{
	public:
		BinaryTree();
		~BinaryTree();

		void print();
		//you must have an opperator initialized for T
		//bool opperator >(const T &);
		void addNode(T val);
		void findNode(T val);
		void deleteNode(T val);
	private:
		Node<T> * root;
		Node<T> * search(T val);
};

#include "BinaryTree_impl.tcc"
