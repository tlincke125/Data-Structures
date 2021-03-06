/****************************************************************/
/*                       Linked List				*/
/****************************************************************/
/**
    CS-11 ASCI Standard 2, LinkedList.hpp
    Purpose: Used to store a dynamically allocated array using the Linked List data structure

    @author Theo Lincke
    @version 1.1 01/02/19 
*/

template <class T>
struct Node{
	T val;

	Node * left;
	Node * right;
};

template <class T>
class BinaryTree{
	public:
		BinaryTree();
		BinaryTree(int size, T * arr);
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
BinaryTree<int> builtIntTree(int * arr);
BinaryTree<char*> buildStringTree(int * arr);

#include "BinaryTree_impl.tcc"
