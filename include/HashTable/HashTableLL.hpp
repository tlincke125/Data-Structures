/****************************************************************/
/*               Linked List				*/
/****************************************************************/
/**
    CS-11 ASCI Standard 2, LinkedList.hpp
    Purpose: Used to store a dynamically allocated array using the Linked List data structure

    @author Theo Lincke
    @version 1.1 01/02/19 
*/
template <class T>
struct nodeData{
    char * hashKey;
    T val;
};

template <class T>
struct Node{
    nodeData<T> val;
	Node * next;
};

template <class T>
class HashTable{
	public:
		HashTable(int size);
        HashTable(int size, int number, T * arr, char ** arrChar);
		~HashTable();


		void print();
		void printTopN(int n);

		void addVal(T val, char * hashKey);
		bool isInTable(T val);

		int getNumCollisions();
		int getNumItems();

		int getTotalNumWords();

	private:

		unsigned int getHash(char * val);
		Node<T> * searchTable(T val);

		Node<T> ** hashTable;
		int size;
		int numItems;
		int numCollisions;
};
#include "HashTableLL_impl.tcc"
