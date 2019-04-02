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
struct Node{
	char ** hashKey;
	T val;
	Node * next;
};

template <class T>
class HashTable{
	public:
		HashTable();
		~HashTable();

		void print();
		void printTopN(int n);

		void addVal(T val);
		bool isInTable(T val);

		int getNumCollisions();
		int getNumItems();

		int getTotalNumWords();

	private:

		unsigned int getHash(T val);
		Node * searchTable(T val);

		Node<T> ** hashTable;
		int size;
		int numItems;
		int numCollisions;
};
